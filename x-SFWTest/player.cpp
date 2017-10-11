#include "Player.h"
#include "sfwdraw.h"


void Player::update()
{
	Vec2 movement = { 0,0 };

	if (sfw::getKey('W'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 1;
	}

	pos += movement;
}

void Player::draw()
{
	sfw::drawCircle(pos.x, pos.y, 30.f);
}
