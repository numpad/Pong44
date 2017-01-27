#include "Item.hpp"

Item::Item(Vec2 pos) {
	Item::pos = pos;
	Item::radius = 24;

	//Item::shape.setPosition(sf::Vector2f(Item::pos.x, Item::pos.y));
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

	if (!Item::smoothShader.loadFromFile("assets/shaders/blur.frag", sf::Shader::Fragment)) {
		puts("Failed to load 'assets/shaders/blur.frag'");
	}

	if (!Item::renderbuffer.create(Item::radius * 3, Item::radius * 3)) {
		puts("Failed to create Item::renderbuffer");
	}

	Item::sprite.setTexture(Item::renderbuffer.getTexture());
	Item::sprite.setOrigin(Item::radius * 1.5, Item::radius * 1.5);
	Item::sprite.setPosition(Item::pos.x, Item::pos.y);
}

bool Item::intersects(Ball &ball) {
	return (ball.pos - Item::pos).length() <= Item::radius;
}

void Item::draw(sf::RenderWindow &window) {
	Item::shape.rotate(3);

	Item::renderbuffer.clear(sf::Color::Transparent);
	Item::renderbuffer.draw(Item::shape, &(Item::smoothShader));
	Item::renderbuffer.display();

	window.draw(Item::sprite, &(Item::outlineShader));
}