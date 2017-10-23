#pragma once

#include "transform.h"

class turret
{
public:
	Transform twist;
	float rotationSpeed;
	turret(float rotSpeed, vec2 pos, vec2 scale, float angle);
	void update(const mat3 &t);
	void draw(const mat3 &t);
};