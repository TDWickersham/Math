#include "enemy.h"
#include "sfwdraw.h"

enemy::enemy()
{
	speed = 2;
	radius = 20;
	enabled = false;
	move.e_parent = nullptr;
	hit.box.extents = { 9,9 };
}

void enemy::update()
{
	dir = norm(dest - move.position);
	move.position += (dir * speed);
}

void enemy::draw()
{
	sfw::drawCircle(move.position.x, move.position.y, radius);
}

bool enemy::checkCollision(bullet b)
{
	if (dist(move.position, b.zoom.position) < radius + b.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool enemy::checkCollision(turret t)
{
	if (dist(move.position, t.twist.position) < radius + t.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
