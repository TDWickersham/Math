#include "Vec3.h"
#include <cmath>
#include <cfloat>

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;

	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;
	return result;

}

vec3 operator+=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON && abs(lhs.y - rhs.y) < FLT_EPSILON && abs(lhs.z - rhs.z) < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;

	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;
	return result;

}

vec3 operator*(const vec3 & lhs, const float & rhs)
{
	vec3 result;

	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	result.z = lhs.z * rhs;
	return result;
}

vec3 operator*(const float & lhs, const vec3 & rhs)
{
	vec3 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	return result;
}

vec3 operator/(const vec3 & lhs, const float & rhs)
{
	vec3 result;

	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;
	result.z = lhs.z / rhs;
	return result;
}

vec3 operator-=(vec3 & lhs, const vec3 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 operator*=(vec3 & lhs, const float & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 operator/=(vec3 & lhs, const float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}
