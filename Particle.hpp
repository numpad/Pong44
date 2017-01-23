#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "Vec2.hpp"
#include <SFML/Graphics.hpp>

class Particle {
	
public:
	bool dead;
	float angle, size;
	sf::Color color;
	Vec2 pos, vel;
	Particle(Vec2, Vec2, sf::Color);
};

#endif