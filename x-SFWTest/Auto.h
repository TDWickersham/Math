#pragma once
#include "collider.h"
#include "Turret.h"

class autoTurret
{
public:
	collider col;
	Transform move;
	vec2 dir;
	bullet pow[100];
	bool enabled = false;
	autoTurret()
	{
		move.e_parent = nullptr;  
	}
	void update();
	void draw();
};