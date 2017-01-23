#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Obstacles {
	std::vector<sf::VertexArray> corners;

public:

	Obstacles();

	void draw(sf::RenderWindow&);
};

#endif