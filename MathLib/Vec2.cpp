#include "Vec2.h"
#include <cmath>
#include <cfloat>

Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs)
{
	Vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;
}

Vec2 &operator+=(Vec2 &lhs, const Vec2 &rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;

	return lhs;
}

bool operator==(const Vec2 & lhs, const Vec2 & rhs)
{
	if ((lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y < FLT_EPSILON))
	{
		return true;
	}
	return false;
}

Vec2 operator-(const Vec2 & lhs, const Vec2 & rhs)
{
	Vec2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;

	return result;
}

Vec2 operator*(const Vec2 & lhs, const float & rhs)
{
	Vec2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;

	return result;
}

Vec2 operator*(const float & lhs, const Vec2 & rhs)
{
	Vec2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

Vec2 operator/(const Vec2 & lhs, const float & rhs)
{
	Vec2 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;

	return result;
}

Vec2 operator-(const Vec2 & lhs)
{
	Vec2 result;
	result.x = -lhs.x;
	result.y = -lhs.y;
	return result;
}

bool operator!=(const Vec2 & lhs, const Vec2 & rhs)
{
	if ((lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y < FLT_EPSILON))
	{
		return false;
	}
	return true;
}

Vec2 &operator-=(Vec2 & lhs, const Vec2 & rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;

	return lhs;
}

Vec2 & operator*=(Vec2 & lhs, const float & rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}

Vec2 & operator/=(Vec2 & lhs, const float & rhs)
{
	lhs.x /= rhs;
	lhs.y /= rhs;

	return lhs;
}

float & Vec2::operator[](unsigned idx)
{
	return v[idx];
}

float Vec2::operator[](unsigned idx) const
{
	return v[idx];
}
