#include "Random.hpp"

Random::Random(float min, float max) : gen(rd()), dis(min, max) {

}

Random::Random() : Random(0.0, 1.0) {

}

void Random::setRange(float min, float max) {
	Random::dis = std::uniform_real_distribution<>(min, max);
}

float Random::operator()() {
	return dis(gen);
}