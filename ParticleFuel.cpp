#include "ParticleFuel.hpp"

ParticleFuel::ParticleFuel() {
	ParticleFuel::colors = std::vector<sf::Color>();
	ParticleFuel::rnd_colorpicker.setRange(0, 1);
	ParticleFuel::rnd_size.setRange(0, 1);
	ParticleFuel::rnd_velx.setRange(0, 1);
	ParticleFuel::rnd_vely.setRange(0, 1);
}

ParticleFuel::ParticleFuel(ParticleFuel &&pfuel) {
	ParticleFuel::colors = pfuel.colors;
	ParticleFuel::rnd_colorpicker.setRange(pfuel.rnd_colorpicker.min, pfuel.rnd_colorpicker.max);
	ParticleFuel::rnd_size.setRange(pfuel.rnd_size.min, pfuel.rnd_size.max);
	ParticleFuel::rnd_velx.setRange(pfuel.rnd_velx.min, pfuel.rnd_velx.max);
	ParticleFuel::rnd_vely.setRange(pfuel.rnd_vely.min, pfuel.rnd_vely.max);
}

ParticleFuel& ParticleFuel::operator=(ParticleFuel &&pfuel) {

	ParticleFuel::colors = pfuel.colors;
	ParticleFuel::rnd_colorpicker = Random(pfuel.rnd_colorpicker.min, pfuel.rnd_colorpicker.max);
	ParticleFuel::rnd_size = Random(pfuel.rnd_size.min, pfuel.rnd_size.max);
	ParticleFuel::rnd_velx = Random(pfuel.rnd_velx.min, pfuel.rnd_velx.max);
	ParticleFuel::rnd_vely = Random(pfuel.rnd_vely.min, pfuel.rnd_vely.max);

	return *this;
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