#pragma once

/*
*	Data structures:
	Vec2
	Vec3
	Vec4

	Mat2
	Mat3
	Mat4

	Operations:
	determinant
	inverse
	rotations
	linear solve
	rotate
	projection
	scale
	translate
	eigenvalues
	eigenvectors
	normalize
	magnitude
	magnitude squared
*/
#include <iostream>;
namespace micromath {
	class Vector2 {
	public:
		float& X() { return vecArr[0]; }
		float& Y() { return vecArr[1]; }
		operator float* () { return (float*)this; }
		
		void print() {
			std::cout << "Vec2 " << vecArr[0] << " " << vecArr[1] << std::endl;
		}
	private:
		float vecArr[2];
	};

	class Vector3 {
	public:
		float& X() { return vecArr[0]; }
		float& Y() { return vecArr[1]; }
		float& Z() { return vecArr[2]; }

		void print() {
			std::cout << "Vec3 " << vecArr[0] << " " << vecArr[1] << " " << vecArr[2] << std::endl;
		}

	private:
		float vecArr[3]
	};
}