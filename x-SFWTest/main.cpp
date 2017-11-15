#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "Turret.h"
#include "mat3.h"
#include "enemy.h"
#include <random>
#include <cmath>
#include <iostream>
#include <ctime>
#include "mons.h"
#include "Auto.h"
#include "Collision.h"

int main()
{
	sfw::initContext();
	srand(time(NULL));
	turret myTurret(1, vec2{ 400,20 }, vec2{2,2}, 0);
	
	enemy minion[20];
	autoTurret ally;
	ally.move.position = vec2{ 370, 20 };
	ally.col.box.extents = vec2{ 350,350 };
	
	mons wallet;

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
		wallet.draw();
		//ally.update();
		//ally.draw();
		if (timer < 0)
		{
			timer = 1;

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
		ally.col.debugDraw(ally.move, RED);
		DrawMatrix(ally.move.getGlobalTransform(), 40);
		ally.update();
		ally.draw();
		for (int i = 0; i < 20; i++)
		{
			doCollision(ally, minion[i]);
		}
		
		for (int j = 0; j < 20; j++)
		{
			minion[j].hit.debugDraw(minion[j].move, MAGENTA);
			if (intersect_AABB(minion[j].hit.box, ally.col.box).penetrationDepth > 0)
			{
				for (int i = 0; i < 100; i++)
				{
					if (ally.pow[i].enabled == true)
					{
						for (int j = 0; j < 20; j++)
						{
							if (minion[j].enabled == true)
							{
								ally.pow[i].hit.debugDraw(ally.pow[i].zoom, CYAN);
								if (intersect_AABB(minion[j].hit.getGlobalBox(minion[j].move), ally.pow[i].hit.getGlobalBox(ally.pow[i].zoom)).penetrationDepth > 0)
								{
									ally.pow[i].enabled = false;
									minion[j].enabled = false;
									wallet.money += 5;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 100; i++)
		{
			if (myTurret.pow[i].enabled == true)
			{
				for (int j = 0; j < 20; j++)
				{
					if (minion[j].enabled == true)
					{
						myTurret.pow[i].hit.debugDraw(myTurret.pow[i].zoom, CYAN);
 						if (intersect_AABB(minion[j].hit.getGlobalBox(minion[j].move), myTurret.pow[i].hit.getGlobalBox(myTurret.pow[i].zoom)).penetrationDepth > 0)
						{
							myTurret.pow[i].enabled = false;
							minion[j].enabled = false;
							wallet.money += 5;
						}
						/*if (minion[j].checkCollision(myTurret.pow[i]))
						{
							myTurret.pow[i].enabled = false;
							minion[j].enabled = false;
							wallet.money += 5;
						}*/
					}
				}
			}
		}



		for (int i = 0; i < 20; i++)
		{
			if (minion[i].enabled == true)
			{
				minion[i].update();
				minion[i].draw();
				if (minion[i].checkCollision(myTurret))
				{
					std::cout << "You died" << std::endl;
				}
			}
		}

		myTurret.update(myTurret.twist.getGlobalTransform());
		myTurret.draw(myTurret.twist.getGlobalTransform());

		DrawMatrix(myTurret.twist.getGlobalTransform(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}
