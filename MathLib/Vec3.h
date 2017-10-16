#pragma once

#include "Vec2.h"

union vec3
{
	float v[3];

	struct { float x, y, z;  };

	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;

	Vec2 xy;

};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);

vec3 operator+=(vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);

vec3 operator-(const vec3 &lhs, const vec3 &rhs);

vec3 operator*(const vec3 &lhs, const float &rhs);

vec3 operator*(const float &lhs, const vec3 &rhs);

vec3 operator/(const vec3 &lhs, const float &rhs);

vec3 operator-=(vec3 &lhs, const vec3 &rhs);

vec3 operator*=(vec3 &lhs, const float &rhs);

vec3 operator/=(vec3 &lhs, const float &rhs);