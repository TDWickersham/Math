#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "Turret.h"
#include "mat3.h"
#include "enemy.h"
#include <random>
#include <cmath>
#include <ctime>

int main()
{
	sfw::initContext();
	srand(time(NULL));
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
				
					/*            10, 42 : 32, 0-31+10 = 10-41
						int randRange(int min, int max) :
							return rand() % (max - min) + min
					*/					
						

					float y = 620;
					float x = rand() %  800;
					//set the position
					minion[i].move.position = vec2{ x,y };
					// position = vec2{x,y};
					//set the dest, which is the turrets position
					minion[i].dest = { 400,20 };
					//enable the minion
					minion[i].enabled = true;
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
