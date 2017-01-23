#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <cmath>
#include <SFML/Graphics.hpp>

class Background {
	sf::Color background, flashColor;
	float flashTime, flashTimeMax;

public:

	Background();
	Background(sf::Color);

	void flash(sf::Color);
	void draw(sf::RenderWindow&);
};

#endif