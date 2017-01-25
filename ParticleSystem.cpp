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
		Particle p(ParticleSystem::position, fuel.getVelocity(), fuel.getColor());
		p.size = fuel.getSize();
		p.color = fuel.getColor();
		p.drag = fuel.getDrag();
		p.maxAge = fuel.getMaxAge();
		ParticleSystem::particles.push_back(p);
	}
}

void ParticleSystem::update() {
	for (size_t i = 0; i < ParticleSystem::particles.size(); ++i) {
		Particle &p = particles.at(i);
		if (p.age > 100) {
			p.size *= 0.9;
			if (p.size < 0.001) {
				ParticleSystem::particles.erase(ParticleSystem::particles.begin() + i);
			}
			continue;
		}
		p.age++;
		
		p.vel *= p.drag;

		p.vel += ParticleSystem::gravity;
		p.pos += p.vel;
	}
}

void ParticleSystem::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < ParticleSystem::particles.size(); ++i) {
		Particle &p = particles.at(i);
		
		ParticleSystem::particleShape.setSize(sf::Vector2f(p.size, p.size));
		ParticleSystem::particleShape.setOrigin(sf::Vector2f(p.size / 2.0, p.size / 2.0));
		ParticleSystem::particleShape.setPosition(p.pos.x, p.pos.y);
		ParticleSystem::particleShape.setFillColor(p.color);
		//ParticleSystem::particleShape.rotate(p.vel.length() * 0.2);
		
		window.draw(ParticleSystem::particleShape);
	}
}

void ParticleSystem::clear() {
	ParticleSystem::particles.clear();
}

void ParticleSystem::setPosition(Vec2 pos) {
	ParticleSystem::position = pos;
}