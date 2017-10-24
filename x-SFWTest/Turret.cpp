#include "Turret.h"
#include "sfwdraw.h"

turret::turret(float rotSpeed, vec2 pos, vec2 scale, float angle)
{
	rotationSpeed = rotSpeed;
	twist.position = pos;
	twist.dimension = scale;
	twist.angle = angle;
	for (int i = 0; i < 100; i++)
	{
		pow[i].enabled = false;
	}
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
		for (int i = 0; i < 100; i++)
		{
			if (pow[i].enabled == false)
			{
				pow[i].enabled = true;
				pow[i].dir = shootDir;
				pow[i].speed = 3;
				pow[i].zoom.position = twist.position;
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

void turret::draw(const mat3 &t)
{
	sfw::drawCircle(t[2].x, t[2].y, 15); 
	for (int i = 0; i < 100; i++)
	{
		if (pow[i].enabled == true)
		{
		pow[i].draw();
		}
	}
}

void bullet::update()
{
	zoom.position += (dir * speed);
	lifeTime -= sfw::getDeltaTime();
	if (lifeTime <= 0)
	{
		enabled = false;
	}
}

void bullet::draw()
{
	sfw::drawCircle(zoom.position.x, zoom.position.y, 2);
}
