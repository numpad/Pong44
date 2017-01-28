#ifndef ITEM_HPP
#define ITEM_HPP

#include "Vec2.hpp"
#include "Ball.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Item {

	Vec2 pos;
	float radius, rotationSpeed;
	
	bool dead;
	
	sf::CircleShape shape;

	sf::Shader outlineShader;
	sf::RenderTexture renderbuffer;
	sf::Sprite sprite;
public:

	Item(Vec2);

	bool isRemovable();

	bool intersects(Ball&);
	void intersect(std::vector<Ball>&);
	void draw(sf::RenderWindow&);
};

#endif