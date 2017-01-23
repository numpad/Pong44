#ifndef VEC2_HPP
#define VEC2_HPP

#include "math.h"

class Vec2 {
public:
	float x, y;

	Vec2() : x{0}, y{0} {}
	Vec2(const Vec2& vec) : x{vec.x}, y{vec.y} {}
	Vec2(float xp, float yp) : x{xp}, y{yp} {}
	Vec2(float both) : Vec2(both, both) {};
	/* Operations */
	Vec2 operator+(const Vec2 b);
	void operator+=(const Vec2 b);

	Vec2 operator-();
	Vec2 operator-(const Vec2 b);
	void operator-=(const Vec2 b);

	Vec2 operator*(const Vec2 b);
	Vec2 operator*(const float n);
	void operator*=(const Vec2 b);
	void operator*=(const float n);

	Vec2 operator/(const Vec2 b);
	Vec2 operator/(const float n);
	void operator/=(const Vec2 b);
	void operator/=(const float n);
	
	bool operator<(const Vec2 b);
	bool operator<=(const Vec2 b);
	bool operator<(const float v);
	bool operator<=(const float v);

	bool operator>(const Vec2 b);
	bool operator>=(const Vec2 b);
	bool operator>(const float v);
	bool operator>=(const float v);
	
	/* Calculate and return length of vector */
	float length();
	void length(float len);
	void limit(float len);

	/* Returns vector with length 1 */
	Vec2 normal();
	void normalize();

	void rotate(float theta);
	float angle(Vec2 b = Vec2(0.0, 0.0));

	Vec2 abs();
	Vec2 swap();

};

#endif