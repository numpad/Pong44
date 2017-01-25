#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

#include "Vec2.hpp"
#include "Random.hpp"
#include "Particle.hpp"
#include "ParticleFuel.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class ParticleSystem {

	Vec2 position, gravity;
	std::vector<Particle> particles;
	sf::RectangleShape particleShape;
	
public:

	ParticleSystem();
	~ParticleSystem();

	void fuel(ParticleFuel&, size_t);
	void update();
	void draw(sf::RenderWindow&);
	void clear();

	void setPosition(Vec2);

};

#endif