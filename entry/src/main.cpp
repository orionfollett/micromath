
#include "micromath.h"
#include <iostream>

using micromath::Vector2;
using micromath::Vector3;

int main() {

	micromath::Vector2 v2;
	v2.X() = 1.0f;
	v2.Y() = 2.0f;

	float* v2Ref = (float*)v2;

	*v2Ref = 100.0f;
	*(v2Ref + 1) = 200.0f;
	v2.print();
	std::cin.get();
	return 0;
}