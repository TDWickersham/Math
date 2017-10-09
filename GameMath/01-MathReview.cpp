#include <iostream>
#include <cmath>

int main()
{
	int x;
	int y;
	int cube;
	float degrees;
	float radians = 0.0174533;
	float radian;
	float degree = 57.2958;
	std::cin >> x;
	y = x * x;
	std::cout << y << std::endl;

	y = x * 2;
	std::cout << y << std::endl;

	std::cout << std::endl;
	std::cout << "please input a number" << std::endl;
	std::cin >> cube;
	cube = cube * cube * cube;
	std::cout << cube << std::endl;

	std::cout << std::endl;
	std::cout << "please input a number for degrees" << std::endl;
	std::cin >> degrees;
	radians = degrees * radians;
	std::cout << radians << std::endl;

	std::cout << std::endl;
	std::cout << "please input a radian" << std::endl;
	std::cin >> radian;
	degree = radian * degree;
	std::cout << degree << std::endl;

	std::cout << std::endl;
	y = (x * 2) + (2 * x) - 7;
	std::cout << y << std::endl;

	std::cout << std::endl;


	system("pause");
}