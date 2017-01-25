#ifndef PADDLE_H
#define PADDLE_H

#include "Player.hpp"
#include "Vec2.hpp"
#include "ParticleFuel.hpp"
#include <SFML/Graphics.hpp>

class Paddle {
	float maxSpeed, acceleration;
	Vec2 vel, acc;
	
	Player player;
	sf::RectangleShape shape;

public:
	ParticleFuel pfuel;
	Vec2 pos, size;

	Paddle(Player&);

	void block();
	void update();
	void draw(sf::RenderWindow&);

	Player &getOwner();
};

#endif