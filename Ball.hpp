#ifndef BALL_HPP
#define BALL_HPP

#include "Background.hpp"
#include "Player.hpp"
#include "Paddle.hpp"
#include "ParticleSystem.hpp"
#include "Random.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Ball {
	Vec2 dir;
	float speed;
	
	Player::ID owner;

	sf::RectangleShape shape;
	float sizeMult;

	sf::Clock aliveFor;
	float startTimeoutSeconds;

	ParticleSystem psystem;
	
	bool isDead, hasStarted;
public:
	float radius;
	Vec2 pos;

	Ball(Vec2, bool, float timeoutSeconds = 0.75);
	Ball(Vec2);

	void setAngle(float);
	void setOwner(Player::ID);
	bool removable();

	bool collides(Paddle&);
	void collide(std::vector<Paddle>&);

	bool checkScored(Background&, float, float);
	void update();
	void draw(sf::RenderWindow&);

	Player::ID getOwner();
};

#endif