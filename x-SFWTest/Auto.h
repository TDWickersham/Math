#pragma once
#include "collider.h"
#include "Turret.h"
#include "enemy.h"

class autoTurret
{
public:
	collider col;
	Transform move;
	vec2 dir;
	bullet pow[100];
	float timer = 2;
	autoTurret()
	{
		move.e_parent = nullptr;
		for (int i = 0; i < 100; i++)
		{
			pow[i].enabled = false;
			pow[i].hit.box.extents = { 5,5 };
		}
	}
	void update();
	void draw();
};

void doCollision(autoTurret &ally, enemy &minion);