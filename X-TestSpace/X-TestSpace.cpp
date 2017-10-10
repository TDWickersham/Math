#include "mathutils.h"
#include "Vec2.h"
#include <iostream>

int main()
{
	int val = min(1, 3);


	Vec2 test;
	test.x = 5;
	test.y = 20;

	Vec2 testB;
	testB.x = 13;
	testB.y = 4;

	Vec2 result = test + testB;

	Vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	bool eq = num == test;
	bool ieq = num == testB;



	system("pause");
}