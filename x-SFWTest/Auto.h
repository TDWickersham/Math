#pragma once
#include "collider.h"

class autoTurret
{
public:
	collider col;
	Transform move;
	bool enabled = false;
	autoTurret()
	{
		move.e_parent = nullptr;  
	}
};