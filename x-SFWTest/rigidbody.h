#pragma once

#include "Vec2.h"
#include "transform.h"


class Rigidbody
{
public:
	vec2 velocity;

	Rigidbody() : velocity{ 0,0 }
	{

	}

	void integrate(Transform &T, float dt)
	{

		T.position += velocity * dt;
	}
};