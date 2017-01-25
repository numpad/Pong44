#ifndef PARTICLEFUEL_HPP
#define PARTICLEFUEL_HPP

#include <SFML/Graphics.hpp>
#include "Random.hpp"
#include "Vec2.hpp"
#include <vector>

class ParticleFuel {
	
	Random rnd_vel;
	Random rnd_angle;
	Random rnd_size;
	Random rnd_drag;
	Random rnd_maxAge;

	std::vector<sf::Color> colors;
	Random rnd_colorpicker;
	

public:
	
	ParticleFuel();
	ParticleFuel(ParticleFuel&&);

	ParticleFuel& operator=(ParticleFuel&&);
	void setVelocity(float, float);
	void setAngle(float, float variance = 0.0);
	void setDrag(float, float);
	void setMaxAge(unsigned int, unsigned int);

	void setSize(float, float);
	void addColor(sf::Color);
	void setColor(sf::Color);
	sf::Color getColor();

	Vec2 getVelocity();
	float getSize();
	float getDrag();
	unsigned int getMaxAge();
};

#endif