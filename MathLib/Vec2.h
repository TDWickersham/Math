#pragma once

union Vec2
{
	float v[2];

	struct { float x, y; };
};

Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs);

Vec2 &operator+=(Vec2 &lhs, const Vec2 &rhs);

bool  operator==(const Vec2 &lhs, const Vec2 &rhs);