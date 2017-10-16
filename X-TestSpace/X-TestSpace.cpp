#include "mathutils.h"
#include "Vec2.h"
#include "Vec3.h"
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

	//vec3 add;
	//add.x = 7;
	//add.y = 1;
	//add.z = 4;
	//vec3 radd;
	//radd.x = 3;
	//radd.y = 2;
	//radd.z = 1;
	//vec3 aRes = add + radd;
	//std::cout << aRes.x << std::endl;
	//std::cout << aRes.y << std::endl;
	//std::cout << aRes.z << std::endl;

	system("pause");
}