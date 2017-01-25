#include "ParticleFuel.hpp"

ParticleFuel::ParticleFuel() {
	ParticleFuel::colors = std::vector<sf::Color>();
	ParticleFuel::rnd_colorpicker.setRange(0, 1);
	ParticleFuel::rnd_size.setRange(0, 1);
	ParticleFuel::rnd_angle.setRange(0, 360);
	ParticleFuel::rnd_vel.setRange(0.0, 10.0);
	ParticleFuel::rnd_drag.setRange(0.955, 0.975);
	ParticleFuel::rnd_maxAge.setRange(90, 230);
	
}

ParticleFuel::ParticleFuel(ParticleFuel &&pfuel) {
	ParticleFuel::colors = pfuel.colors;
	ParticleFuel::rnd_colorpicker.setRange(pfuel.rnd_colorpicker.min, pfuel.rnd_colorpicker.max);
	ParticleFuel::rnd_size.setRange(pfuel.rnd_size.min, pfuel.rnd_size.max);
	ParticleFuel::rnd_angle.setRange(pfuel.rnd_angle.min, pfuel.rnd_angle.max);
	ParticleFuel::rnd_vel.setRange(pfuel.rnd_vel.min, pfuel.rnd_vel.max);
	ParticleFuel::rnd_drag.setRange(pfuel.rnd_drag.min, pfuel.rnd_drag.max);
	ParticleFuel::rnd_maxAge.setRange(pfuel.rnd_maxAge.min, pfuel.rnd_maxAge.max);
}

ParticleFuel& ParticleFuel::operator=(ParticleFuel &&pfuel) {
	ParticleFuel::colors = pfuel.colors;
	ParticleFuel::rnd_colorpicker = Random(pfuel.rnd_colorpicker.min, pfuel.rnd_colorpicker.max);
	ParticleFuel::rnd_size = Random(pfuel.rnd_size.min, pfuel.rnd_size.max);
	ParticleFuel::rnd_angle.setRange(pfuel.rnd_angle.min, pfuel.rnd_angle.max);
	ParticleFuel::rnd_vel.setRange(pfuel.rnd_vel.min, pfuel.rnd_vel.max);
	ParticleFuel::rnd_drag.setRange(pfuel.rnd_drag.min, pfuel.rnd_drag.max);
	ParticleFuel::rnd_maxAge.setRange(pfuel.rnd_maxAge.min, pfuel.rnd_maxAge.max);
	return *this;
}

void ParticleFuel::setAngle(float angleDeg, float variance) {
	ParticleFuel::rnd_angle.setRange((angleDeg - variance / 2.0) * (M_PI / 180.0), (angleDeg + variance / 2.0) * (M_PI / 180.0));
}

void ParticleFuel::setVelocity(float min, float max) {
	ParticleFuel::rnd_vel.setRange(min, max);
}

void ParticleFuel::setSize(float min, float max) {
	ParticleFuel::rnd_size.setRange(min, max);
}

void ParticleFuel::setDrag(float min, float max) {
	ParticleFuel::rnd_drag.setRange(min, max);
}

void ParticleFuel::setMaxAge(unsigned int min, unsigned int max) {
	ParticleFuel::rnd_maxAge.setRange((float)min, (float)max);
}

Vec2 ParticleFuel::getVelocity() {
	const float angle = ParticleFuel::rnd_angle();
	const float vel = ParticleFuel::rnd_vel();
	return Vec2(sin(angle) * vel, cos(angle) * vel);
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

float ParticleFuel::getDrag() {
	return ParticleFuel::rnd_drag();
}

unsigned int ParticleFuel::getMaxAge() {
	return (unsigned int)ParticleFuel::rnd_maxAge();
}