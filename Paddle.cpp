#include "Paddle.hpp"

Paddle::Paddle(Player &player) : player(player) {
	Paddle::maxSpeed = 13.85;
	Paddle::acceleration = 0.89;

	Paddle::pos = Vec2(400 + 370 * player.getSide().x, 400 + 370 * player.getSide().y);
	Paddle::vel = Vec2(0.0, 0.0);
	Paddle::acc = Vec2(Paddle::acceleration) * player.getSide().abs().swap();

	float length = 170.0,
		  width  =  30.0;
	Paddle::size = Paddle::player.getSide().x != 0 ? Vec2(width, length) : Vec2(length, width);

	/* Shape */
	Paddle::shape.setSize(sf::Vector2f(Paddle::size.x, Paddle::size.y));
	Paddle::shape.setFillColor(Paddle::player.getColor());
	Paddle::shape.setOrigin(Paddle::size.x / 2.0, Paddle::size.y / 2.0);
	Paddle::shape.setPosition(Paddle::pos.x, Paddle::pos.y);

	/* ParticleFuel */
	const float sidex = Paddle::player.getSide().x;
	const float sidey = Paddle::player.getSide().y;
	float angle = 90.0 * ((sidex + 2 * sidex) + (sidey + 1 * fabs(sidey)));
	Paddle::pfuel.setAngle(angle, 180.0);
	Paddle::pfuel.setVelocity(0.0, 7.0);
	Paddle::pfuel.setSize(1.0, 4.0);
	Paddle::pfuel.addColor(Paddle::player.getColor());
	Paddle::pfuel.addColor(Paddle::player.getColor() * sf::Color(220, 220, 220));
	Paddle::pfuel.addColor(Paddle::player.getColor() * sf::Color(100, 100, 100));
	
}

void Paddle::block() {
	float sidex = Paddle::player.getSide().abs().x;
	float sidey = Paddle::player.getSide().abs().y;
	
	if (sidey) {
		if (Paddle::pos.x < 47.0 + Paddle::size.x / 2.0) {
			Paddle::pos.x = 47.0 + Paddle::size.x / 2.0;
			Paddle::vel.x = 0.0;
		} else if (Paddle::pos.x > 800.0 - 47.0 - Paddle::size.x / 2.0) {
			Paddle::pos.x = 800.0 - 47.0 - Paddle::size.x / 2.0;
			Paddle::vel.x = 0.0;
		}
	}

	if (sidex) {
		if (Paddle::pos.y < 47.0 + Paddle::size.y / 2.0) {
			Paddle::pos.y = 47.0 + Paddle::size.y / 2.0;
			Paddle::vel.y = 0.0;
		} else if (Paddle::pos.y > 800.0 - 47.0 - Paddle::size.y / 2.0) {
			Paddle::pos.y = 800.0 - 47.0 - Paddle::size.y / 2.0;
			Paddle::vel.y = 0.0;
		}
	}
}

void Paddle::update() {
	const bool keydown_left = sf::Keyboard::isKeyPressed(Paddle::player.left);
	const bool keydown_right = sf::Keyboard::isKeyPressed(Paddle::player.right);
	
	if (keydown_left && !(keydown_left && keydown_right)) {
		Paddle::vel -= Paddle::acc;
		/* Make turning around faster */
		if (Paddle::vel.x + Paddle::vel.y > 0.0) {
			Paddle::vel -= Paddle::acc * 1.75;
		}
	}
	if (keydown_right && !(keydown_left && keydown_right)) {
		Paddle::vel += Paddle::acc;
		/* Make turning around faster */
		if (Paddle::vel.x + Paddle::vel.y < 0.0) {
			Paddle::vel += Paddle::acc * 1.75;
		}
	}

	if ((!keydown_left && !keydown_right) || (keydown_left && keydown_right)) {
		Paddle::vel *= 0.875;
	}
	
	Paddle::block();
	Paddle::vel.limit(Paddle::maxSpeed);
	Paddle::pos += Paddle::vel;

	Paddle::shape.setPosition(Paddle::pos.x, Paddle::pos.y);
}

void Paddle::draw(sf::RenderWindow &window) {
	const float lengthStretchPercent = 0.1;
	const float widthStretchPercent = 0.1;
	Paddle::shape.setScale(
		1.0 + (Paddle::vel.length() / Paddle::maxSpeed * lengthStretchPercent) * (-fabs(Paddle::player.getSide().x)) + 1.0 * (Paddle::vel.length() / Paddle::maxSpeed * widthStretchPercent) * (fabs(Paddle::player.getSide().y)),
		1.0 + (Paddle::vel.length() / Paddle::maxSpeed * lengthStretchPercent) * (-fabs(Paddle::player.getSide().y)) + 1.0 * (Paddle::vel.length() / Paddle::maxSpeed * widthStretchPercent) * (fabs(Paddle::player.getSide().x))
	);
	window.draw(Paddle::shape);
}


Player &Paddle::getOwner() {
	return player;
}