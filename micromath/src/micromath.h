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

	Unit tests

*/
#include <iostream>

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
		float vecArr[2] = {0, 0};
	};

	class Vector3 {
	public:
		float& X() { return vecArr[0]; }
		float& Y() { return vecArr[1]; }
		float& Z() { return vecArr[2]; }
		operator float* () { return (float*)this; }
		void print() {
			std::cout << "Vec3 " << vecArr[0] << " " << vecArr[1] << " " << vecArr[2] << std::endl;
		}

	private:
		float vecArr[3] = { 0, 0, 0 };
	};

	class Vector4 {
	public:
		float& X() { return vecArr[0]; }
		float& Y() { return vecArr[1]; }
		float& Z() { return vecArr[2]; }
		float& W() { return vecArr[3]; }
		operator float* () { return (float*)this; }
		void print() {
			std::cout << "Vec4 " << vecArr[0] << " " << vecArr[1] << " " << vecArr[2] << " " << vecArr[3] << std::endl;
		}
	private: 
		float vecArr[4] = {0, 0, 0, 0};
	};

	//memory layout: 1D array to minimize memory allocation and deallocation
	//override indexing operator to make it look like a 2D array
	class Matrix2 {

	public:
		//returns pointer to first item in the row
		float* operator[] (size_t index) {
			if (index < 0 || index > 1) {
				throw std::out_of_range("Index out of range.");
			}
			return &arr[index * 2];
		}
	private:
		float arr[4] = { 0,0,0,0 };
	};
}