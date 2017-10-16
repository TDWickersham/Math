#pragma once

union Vec2
{
	float v[2];

	struct { float x, y; };

	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;
};

Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs);

Vec2 &operator+=(Vec2 &lhs, const Vec2 &rhs);

bool  operator==(const Vec2 &lhs, const Vec2 &rhs);

Vec2 operator-(const Vec2 &lhs, const Vec2 &rhs);

Vec2 operator*(const Vec2 &lhs, const float &rhs);

Vec2 operator*(const float &lhs, const Vec2 &rhs);

Vec2 operator/(const Vec2 &lhs, const float &rhs);

Vec2 operator-(const Vec2 &lhs);

bool  operator!=(const Vec2 &lhs, const Vec2 &rhs);

Vec2 &operator-=(Vec2 &lhs, const Vec2 &rhs);

Vec2 &operator*=(Vec2 &lhs, const float &rhs);

Vec2 &operator/=(Vec2 &lhs, const float &rhs);