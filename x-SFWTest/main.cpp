#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "Turret.h"
#include "mat3.h"

#include <cmath>

int main()
{
	sfw::initContext();

	turret myTurret(1, vec2{ 400,20 }, vec2{2,2}, 0);

	Transform myBaby;
	myBaby.position = vec2{ 0, 10 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTurret.twist;

	while (sfw::stepContext())
	{
		//Rotate your object around clockwise
		float t = sfw::getTime();

		myTurret.update(myTurret.twist.getGlobalTransform());
		myTurret.draw(myTurret.twist.getGlobalTransform());

		DrawMatrix(myTurret.twist.getGlobalTransform(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 30);
	}

	sfw::termContext();
}
