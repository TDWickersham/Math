#pragma once

#include "transform.h"
#include "Turret.h"
#include "collider.h"

class enemy
{
public:
	float radius;
	collider hit;
	Transform move;
	bool enabled;
	vec2 dir;
	vec2 dest;
	//enemy spawn[20];
	float speed = 1;
	enemy();
	void update();
	void draw();
	bool checkCollision(bullet b);
	bool checkCollision(turret t);
};
