#include "Auto.h"
#include "Turret.h"

void autoTurret::update()
{
	for (int i = 0; i < 100; i++)
	{
		if (pow[i].enabled == false)
		{
			pow[i].enabled = true;
			pow[i].dir = dir;
			pow[i].speed = 3;
			pow[i].zoom.position = move.position;
			pow[i].lifeTime = 5;
			break;
		}
	}
}

void autoTurret::draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (pow[i].enabled == true)
		{
			pow[i].draw();
		}
	}
}
