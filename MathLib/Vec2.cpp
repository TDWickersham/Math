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
