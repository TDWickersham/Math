#include "Auto.h"
#include "Turret.h"
#include "sfwdraw.h"
#include "Collision.h"


void autoTurret::update()
{
	timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 2;
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
	for (int i = 0; i < 100; i++)
	{
		if (pow[i].enabled == true)
		{
			pow[i].update();
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

void doCollision(autoTurret & ally, enemy & minion)
{
	Collision hit = collides(ally.move, ally.col, minion.move, minion.hit);
	if (hit.penetrationDepth > 0)
	{
		ally.dir = norm(minion.move.position - ally.move.position);
	}
}
