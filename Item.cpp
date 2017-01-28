#include "Item.hpp"

Item::Item(Vec2 pos) {
	Item::pos = pos;
	Item::radius = 24;
	Item::rotationSpeed = 3.0;
	Item::dead = false;

	Item::shape.setRadius(Item::radius);
	Item::shape.setOrigin(sf::Vector2f(Item::radius, Item::radius));
	Item::shape.setPosition(sf::Vector2f(Item::radius * 1.5, Item::radius * 1.5));
	Item::shape.setFillColor(sf::Color::Transparent);
	Item::shape.setOutlineColor(sf::Color(233, 233, 233));
	Item::shape.setOutlineThickness(4.5);
	Item::shape.setPointCount(6);

	if (!Item::outlineShader.loadFromFile("assets/shaders/multicolor.frag", sf::Shader::Fragment)) {
		puts("Failed to load 'assets/shaders/multicolor.frag'");
	}
	Item::outlineShader.setUniform("texture", sf::Shader::CurrentTexture);

	if (!Item::renderbuffer.create(Item::radius * 3, Item::radius * 3)) {
		puts("Failed to create Item::renderbuffer");
	}

	Item::sprite.setTexture(Item::renderbuffer.getTexture());
	Item::sprite.setOrigin(Item::radius * 1.5, Item::radius * 1.5);
	Item::sprite.setPosition(Item::pos.x, Item::pos.y);
}

bool Item::isRemovable() {
	return Item::dead;
}

bool Item::intersects(Ball &ball) {
	return (ball.pos - Item::pos).length() <= Item::radius + ball.radius;

}

void Item::intersect(std::vector<Ball> &balls) {
	for (size_t i = 0; i < balls.size(); ++i) {
		if (Item::intersects(balls.at(i))) {
			Item::rotationSpeed = 20.0;
		}
	}
}

void Item::draw(sf::RenderWindow &window) {
	if (Item::rotationSpeed > 0.1) {
		Item::rotationSpeed *= 0.9;
	} else {
		Item::rotationSpeed = 0.0;
	}
	Item::shape.rotate(Item::rotationSpeed);

	Item::renderbuffer.clear(sf::Color::Transparent);
	Item::renderbuffer.draw(Item::shape);
	Item::renderbuffer.display();

	window.draw(Item::sprite, &(Item::outlineShader));
}