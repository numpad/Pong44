#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem() {
	ParticleSystem::position = Vec2(0.0, 0.0);
	ParticleSystem::gravity = Vec2(0.0, 0.0);

	ParticleSystem::particles = std::vector<Particle>();
}

ParticleSystem::~ParticleSystem() {

}

void ParticleSystem::fuel(ParticleFuel &fuel, size_t count) {

	for (size_t i = 0; i < count; ++i) {
		Particle p(ParticleSystem::position, fuel.getVelocity(), sf::Color(233, 233, 233));
		p.size = fuel.getSize();
		p.color = fuel.getColor();
		ParticleSystem::particles.push_back(p);
	}
}

void ParticleSystem::update() {
	for (size_t i = 0; i < ParticleSystem::particles.size(); ++i) {
		Particle &p = particles.at(i);

		p.vel += ParticleSystem::gravity;
		p.pos += p.vel;
	}
}

void ParticleSystem::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < ParticleSystem::particles.size(); ++i) {
		Particle &p = particles.at(i);
		
		ParticleSystem::particleShape.setSize(sf::Vector2f(3.0, 3.0));
		ParticleSystem::particleShape.setOrigin(sf::Vector2f(1.5, 1.5));
		ParticleSystem::particleShape.setPosition(p.pos.x, p.pos.y);
		ParticleSystem::particleShape.setFillColor(p.color);
		
		window.draw(ParticleSystem::particleShape);
	}
}

void ParticleSystem::clear() {
	ParticleSystem::particles.clear();
}

void ParticleSystem::setPosition(Vec2 pos) {
	ParticleSystem::position = pos;
}