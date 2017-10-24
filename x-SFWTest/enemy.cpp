#include "enemy.h"
#include "sfwdraw.h"

enemy::enemy()
{
	speed = 4;
	radius = 20;
	enabled = false;
}

void enemy::update()
{
	dir = norm(move.position - dest);
	move.position += (dir * speed);
}

void enemy::draw()
{
	sfw::drawCircle(move.position.x, move.position.y, radius);
}
