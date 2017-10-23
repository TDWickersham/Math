#include "Turret.h"
#include "sfwdraw.h"

turret::turret(float rotSpeed, vec2 pos, vec2 scale, float angle)
{
	rotationSpeed = rotSpeed;
	twist.position = pos;
	twist.dimension = scale;
	twist.angle = angle;
}

void turret::update(const mat3 &t)
{
	vec2 shootDir = norm(t[1].xy);
	if (sfw::getKey('A'))
	{
		twist.angle += rotationSpeed;
	}
	if (sfw::getKey('D'))
	{
		twist.angle -= rotationSpeed;
	}
	if (sfw::getKey(' '))
	{
		//Bullet.Position += shootDir
		
	}

}

void turret::draw(const mat3 &t)
{
	sfw::drawCircle(t[2].x, t[2].y, 15); 
}
