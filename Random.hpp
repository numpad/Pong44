#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

class Random {
	std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

public:
	Random(float, float);
	Random();
	
	void setRange(float, float);

	float operator()();
};

#endif