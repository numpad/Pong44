#ifndef PLAYER_H
#define PLAYER_H

#include "Vec2.hpp"
#include "ParticleFuel.hpp"
#include <SFML/Graphics.hpp>

class Player {
public:
	sf::Keyboard::Key left, right, use;
	
	enum ID {
		PLAYER_NONE,
		PLAYER_1, PLAYER_2, PLAYER_3, PLAYER_4
	};

	enum SIDE {
		SIDE_TOP, SIDE_BOTTOM,
		SIDE_LEFT, SIDE_RIGHT
	};

	Player(ID, SIDE);

	void setSide(SIDE);
	void setSide(int, int);
	void setColor(sf::Color);
	void setKeys(sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key);
	
	static sf::Color colorOf(ID);

	Vec2 getSide();
	sf::Color getColor();
	ID getID();
private:
	Vec2 side;
	sf::Color color;

	ID id;
};

#endif