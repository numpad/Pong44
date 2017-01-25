#include "Ball.hpp"

Ball::Ball(Vec2 startPos, bool startImmediately, float timeoutSeconds) {
	Ball::pos = startPos;
	Ball::speed = 7.75;
	Ball::radius = 9.0;
	Ball::isDead = false;
	Ball::startTimeoutSeconds = (startImmediately ? 0.0 : timeoutSeconds);
	Ball::hasStarted = false;
	Ball::sizeMult = 1.0;
	float angle = rand() % 360;
	Ball::setAngle(angle);

	Ball::owner = Player::PLAYER_NONE;

	Ball::shape.setFillColor(Player::colorOf(Player::PLAYER_NONE));
	Ball::shape.setSize(sf::Vector2f(Ball::radius * 2.0, Ball::radius * 2.0));
	Ball::shape.setOrigin(Ball::shape.getSize().x / 2.0, Ball::shape.getSize().y / 2.0);
	Ball::shape.setPosition(Ball::pos.x, Ball::pos.y);

}

Ball::Ball(Vec2 startPos) : Ball(startPos, false) {

}

void Ball::setAngle(float deg) {
	float dx = sin(deg * (M_PI / 180.0));
	float dy = cos(deg * (M_PI / 180.0));

	Ball::dir = Vec2(dx, dy);
}

void Ball::setOwner(Player::ID id) {
	Ball::owner = id;
	Ball::shape.setFillColor(Player::colorOf(id));
}

bool Ball::removable() {
	return Ball::isDead;
}

bool Ball::collides(Paddle &paddle) {
	if (paddle.pos.x - paddle.size.x / 2.0 <= Ball::pos.x + Ball::radius
	 && paddle.pos.x + paddle.size.x / 2.0 >= Ball::pos.x - Ball::radius) {
		if (paddle.pos.y - paddle.size.y / 2.0 <= Ball::pos.y + Ball::radius
		 && paddle.pos.y + paddle.size.y / 2.0 >= Ball::pos.y - Ball::radius) {
		 	return true;
		 }
	 }

	 return false;
}

void Ball::collide(std::vector<Paddle> &paddles) {
	for (size_t i = 0; i < paddles.size(); ++i) {
		if (Ball::collides(paddles.at(i))) {
			/* Set owner */
			Ball::setOwner(paddles.at(i).getOwner().getID());

			/* Juicy effect */
			Ball::sizeMult = 1.95;

			/* Angle calculation */
			const float sidex = paddles.at(i).getOwner().getSide().x;
			const float sidey = paddles.at(i).getOwner().getSide().y;
			
			/* Bounce in direction we want, depending on where we hit the Paddle */
			Vec2 dist = Ball::pos - paddles.at(i).pos;
			/* Don't let the Paddle control the ball that much */
			dist -= dist * (Vec2(sidey, sidex).abs() * 0.7);
			float angle = (dist).angle() - 90.0 * (-fabs(sidex) + fabs(sidey));
			Ball::setAngle(angle);

			/* Bounce in other direction */
			if (fabs(sidex)) {
				Ball::dir.x = fabs(Ball::dir.x) * -sidex;
			}
			if (fabs(sidey)) {
				Ball::dir.y = fabs(Ball::dir.y) * -sidey;
			}

			/* Add juicy particles */
			Ball::psystem.fuel(paddles.at(i).pfuel, 30);
		}
	}
}

void Ball::update() {
	/* Wait x seconds until ball starts moving */
	if (Ball::aliveFor.getElapsedTime().asSeconds() < Ball::startTimeoutSeconds) {
		const float timeoutLeft = Ball::aliveFor.getElapsedTime().asSeconds() / Ball::startTimeoutSeconds;
		Ball::shape.rotate(18.0 * (1.0 - timeoutLeft));
		return;
	}

	if (!Ball::hasStarted) {
		Ball::hasStarted = true;

		ParticleFuel pfuel;
		pfuel.setAngle(0.0, 360.0);
		pfuel.setVelocity(1.0, 5.0);
		pfuel.setSize(1.0, 4.0);
		pfuel.setDrag(0.935, 0.965);
		pfuel.setColor(Player::colorOf(Player::PLAYER_NONE));
		psystem.setPosition(Ball::pos);

		Ball::psystem.fuel(pfuel, 70);
	}

	/* Update position */
	Ball::shape.setRotation(Ball::dir.angle(Vec2(0.0, 0.0)));
	Ball::dir.length(Ball::speed);
	Ball::pos += Ball::dir;

	if (Ball::sizeMult > 1.0) {
		Ball::sizeMult *= 0.85;
	} else {
		Ball::sizeMult = 1.0;
	}

	/* Update ParticleSystem */
	Ball::psystem.setPosition(Ball::pos);
	Ball::psystem.update();
}

bool Ball::checkScored(Background &background, float sizex, float sizey) {
	if (Ball::pos.x < 0.0 || Ball::pos.y < 0.0 || Ball::pos.x > sizex || Ball::pos.y > sizey) {
		Ball::isDead = true;
		background.flash(Player::colorOf(Ball::owner));
		return true;
	}

	return false;
}

void Ball::draw(sf::RenderWindow &window) {
	Ball::shape.setPosition(Ball::pos.x, Ball::pos.y);
	Ball::shape.setScale(Ball::sizeMult, Ball::sizeMult);
	
	window.draw(Ball::shape);
	Ball::psystem.draw(window);
}

Player::ID Ball::getOwner() { 
	return owner;
}