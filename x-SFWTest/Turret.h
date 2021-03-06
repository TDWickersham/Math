#pragma once

#include "transform.h"
#include "collider.h"

class bullet
{

public:
	bool enabled;
	collider hit;
	Transform zoom;
	vec2 dir;
	float lifeTime = 5;
	float speed;
	float radius = 2;
	void update();
	void draw();
};

class turret
{
public:
	collider hurt;
	Transform twist;
	float radius = 15;
	float rotationSpeed;
	bullet pow[100];
	turret(float rotSpeed, vec2 pos, vec2 scale, float angle);
	void update(const mat3 &t);
	void draw(const mat3 &t);

};

