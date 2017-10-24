#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "Turret.h"
#include "mat3.h"
#include "enemy.h"
#include <random>
#include <cmath>

int main()
{
	sfw::initContext();

	turret myTurret(1, vec2{ 400,20 }, vec2{2,2}, 0);

	enemy minion[20];

	Transform myBaby;
	myBaby.position = vec2{ 0, 10 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTurret.twist;
	float timer = 4;
	while (sfw::stepContext())
	{
		//Rotate your object around clockwise
		float t = sfw::getDeltaTime();
		timer -= t;

		if (timer < 0)
		{
			timer = 4;

			for (int i = 0; i < 20; i++)
			{
				if (minion[i].enabled == false)
				{
				
					float y = 620;
					float x = rand & 800;
					//set the position
					minion.position = vec2{ x,y };
					// position = vec2{x,y};
					//set the dest, which is the turrets position
					//enable the minion
					break;
				}
			}



		}



		for (int i = 0; i < 20; i++)
		{
			if (minion[i].enabled == true)
			{
				minion[i].update();
				minion[i].draw();
			}
		}

		myTurret.update(myTurret.twist.getGlobalTransform());
		myTurret.draw(myTurret.twist.getGlobalTransform());

		DrawMatrix(myTurret.twist.getGlobalTransform(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}
