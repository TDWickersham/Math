#include "enemy.h"
#include "sfwdraw.h"

enemy::enemy()
{
	speed = 2;
	radius = 20;
	enabled = false;
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
