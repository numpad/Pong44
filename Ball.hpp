#ifndef BALL_HPP
#define BALL_HPP

#include "Player.hpp"
#include "Paddle.hpp"
#include "ParticleSystem.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Ball {
	Vec2 dir;
	float speed;
	
	Player::ID owner;

	sf::RectangleShape shape;
	float radius, sizeMult;

	sf::Clock aliveFor;
	float startTimeoutSeconds;

	ParticleSystem psystem;

	bool isDead;
public:
	Vec2 pos;

	Ball(Vec2, bool);
	Ball(Vec2);

	void setAngle(float);
	void setOwner(Player::ID);
	bool removable();

	bool collides(Paddle&);
	void collide(std::vector<Paddle>&);
	void update();
	void draw(sf::RenderWindow&);

	Player::ID getOwner();
};

#endif