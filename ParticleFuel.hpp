#ifndef PARTICLEFUEL_HPP
#define PARTICLEFUEL_HPP

#include <SFML/Graphics.hpp>
#include "Random.hpp"
#include "Vec2.hpp"
#include <vector>

class ParticleFuel {
	
	Random rnd_velx, rnd_vely, rnd_size;
	
	std::vector<sf::Color> colors;
	Random rnd_colorpicker;

public:
	
	ParticleFuel();

	void setVelocity(Vec2, Vec2);
	void setSize(float, float);
	void addColor(sf::Color);
	void setColor(sf::Color);

	Vec2 getVelocity();
	float getSize();
	sf::Color getColor();
};

#endif