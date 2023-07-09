
#include "micromath.h";
#include <iostream>;

using micromath::Vector2;



int main() {
	
	Vector2 v;
	v.X() = 1;
	v.Y() = 2;

	v.print();

	v.X() = 100;
	v.print();

	float result = v.X() + v.Y();
	std::cout << result << std::endl;



	std::cout << *((float*)v) << std::endl;

	std::cin.get();
	return 0;
}