#pragma once

#include "transform.h"


class enemy
{
public:
	float radius;
	Transform move;
	bool enabled;
	vec2 dir;
	vec2 dest;
	//enemy spawn[20];
	float speed = 1;
	enemy();
	void update();
	void draw();
};
