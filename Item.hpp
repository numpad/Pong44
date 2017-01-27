#ifndef ITEM_HPP
#define ITEM_HPP

#include "Vec2.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>

class Item {

	Vec2 pos;
	float radius;

	sf::CircleShape shape;

	sf::Shader outlineShader, smoothShader;
	sf::RenderTexture renderbuffer;
	sf::Sprite sprite;
public:

	Item(Vec2);

	bool intersects(Ball&);

	void draw(sf::RenderWindow&);
};

#endif