#include "ParticleFuel.hpp"

ParticleFuel::ParticleFuel() {
	ParticleFuel::colors = std::vector<sf::Color>();
	ParticleFuel::rnd_colorpicker.setRange(0, 1);
	ParticleFuel::rnd_size.setRange(0, 1);
	ParticleFuel::rnd_velx.setRange(0, 1);
	ParticleFuel::rnd_vely.setRange(0, 1);
}

void ParticleFuel::setVelocity(Vec2 min, Vec2 max) {
	ParticleFuel::rnd_velx.setRange(min.x, max.x);
	ParticleFuel::rnd_vely.setRange(min.y, max.y);
}

void ParticleFuel::setSize(float min, float max) {
	ParticleFuel::rnd_size.setRange(min, max);
}

Vec2 ParticleFuel::getVelocity() {
	return Vec2(
		ParticleFuel::rnd_velx(),
		ParticleFuel::rnd_vely()
	);
}

float ParticleFuel::getSize() {
	return ParticleFuel::rnd_size();
}

void ParticleFuel::addColor(sf::Color color) {
	ParticleFuel::colors.push_back(color);
}

void ParticleFuel::setColor(sf::Color color) {
	ParticleFuel::colors.clear();
	ParticleFuel::colors.push_back(color);
}

sf::Color ParticleFuel::getColor() {
	return ParticleFuel::colors.at((int)(ParticleFuel::rnd_colorpicker() * ParticleFuel::colors.size()));
}