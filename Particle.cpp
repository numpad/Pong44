#include "Particle.hpp"

Particle::Particle(Vec2 pos, Vec2 vel, sf::Color color) {
	Particle::pos = pos;
	Particle::vel = vel;
	Particle::color = color;
	Particle::angle = 0.0;
	Particle::size = 2.0;
	Particle::dead = false;
}

