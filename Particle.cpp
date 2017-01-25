#include "Particle.hpp"

Particle::Particle(Vec2 pos, Vec2 vel, sf::Color color) {
	Particle::pos = pos;
	Particle::vel = vel;
	Particle::color = color;
	Particle::drag = 0.996;
	Particle::size = 2.0;
	Particle::dead = false;
	Particle::age = 0;
	Particle::maxAge = 100;
}

