#pragma once

#include "transform.h"

class bullet
{

public:
	bool enabled;
	Transform zoom;
	vec2 dir;
	float lifeTime = 5;
	float speed;
	void update();
	void draw();
};

class turret
{
public:
	Transform twist;
	float rotationSpeed;
	bullet pow[100];
	turret(float rotSpeed, vec2 pos, vec2 scale, float angle);
	void update(const mat3 &t);
	void draw(const mat3 &t);

};

