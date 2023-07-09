#include "pch.h"
#include "CppUnitTest.h"
#include "micromath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace micromathunittests
{
	TEST_CLASS(micromathunittests)
	{
	public:
		TEST_METHOD(Init_Vector2)
		{
			micromath::Vector2 v2;
			Assert::AreEqual(v2.X(), 0.f);
			Assert::AreEqual(v2.Y(), 0.f);

			v2.X() = 1.0f;
			v2.Y() = 2.0f;
			Assert::AreEqual(v2.X(), 1.0f);
			Assert::AreEqual(v2.Y(), 2.0f);
		}

		TEST_METHOD(Init_Vector3) {
			micromath::Vector3 v3;
			Assert::AreEqual(v3.X(), 0.f);
			Assert::AreEqual(v3.Y(), 0.f);
			Assert::AreEqual(v3.Z(), 0.f);

			v3.X() = 3.0f;
			v3.Y() = 4.0f;
			v3.Z() = 5.0f;
			Assert::AreEqual(v3.X(), 3.0f);
			Assert::AreEqual(v3.Y(), 4.0f);
			Assert::AreEqual(v3.Z(), 5.0f);
		}

		TEST_METHOD(Init_Vector4) {
			micromath::Vector4 v4;
			Assert::AreEqual(v4.X(), 0.f);
			Assert::AreEqual(v4.Y(), 0.f);
			Assert::AreEqual(v4.Z(), 0.f);
			Assert::AreEqual(v4.W(), 0.f);

			v4.X() = 6.0f;
			v4.Y() = 7.0f;
			v4.Z() = 8.0f;
			v4.W() = 9.0f;
			Assert::AreEqual(v4.X(), 6.0f);
			Assert::AreEqual(v4.Y(), 7.0f);
			Assert::AreEqual(v4.Z(), 8.0f);
			Assert::AreEqual(v4.W(), 9.0f);
		}

		TEST_METHOD(Ref_Vector2) {
			micromath::Vector2 v2;
			v2.X() = 1.0f;
			v2.Y() = 2.0f;

			float* v2Ref = (float*)v2;

			*v2Ref = 100.0f;
			*(v2Ref + 1) = 200.0f;
			Assert::AreEqual(v2.X(), 100.0f);
			Assert::AreEqual(v2.Y(), 200.0f);
		}

		TEST_METHOD(Ref_Vector3) {
			micromath::Vector3 v3;
			v3.X() = 1.0f;
			v3.Y() = 2.0f;
			v3.Z() = 3.0f;

			float* v3Ref = (float*)v3;
			*v3Ref *= 100.0f;
			*(v3Ref + 1) *= 100.0f;
			*(v3Ref + 2) *= 100.0f;

			Assert::AreEqual(v3.X(), 100.0f);
			Assert::AreEqual(v3.Y(), 200.0f);
			Assert::AreEqual(v3.Z(), 300.0f);
		}

		TEST_METHOD(Ref_Vector4) {
			micromath::Vector4 v4;
			v4.X() = 1.0f;
			v4.Y() = 2.0f;
			v4.Z() = 3.0f;
			v4.W() = 4.0f;

			float* v4Ref = (float*)v4;
			*v4Ref *= 100.0f;
			*(v4Ref + 1) *= 100.0f;
			*(v4Ref + 2) *= 100.0f;
			*(v4Ref + 3) *= 100.0f;

			Assert::AreEqual(v4.X(), 100.0f);
			Assert::AreEqual(v4.Y(), 200.0f);
			Assert::AreEqual(v4.Z(), 300.0f);
			Assert::AreEqual(v4.W(), 400.0f);
		}

		TEST_METHOD(Init_Matrix2) {
			auto throwsInvalidFunc = [] {
				micromath::Matrix2 m;
				m[2];
			};

			auto throwsInvalidFunc2 = [] {
				micromath::Matrix2 m;
				m[-1];
			};

			Assert::ExpectException<std::out_of_range>(throwsInvalidFunc);
			Assert::ExpectException<std::out_of_range>(throwsInvalidFunc2);
			
			micromath::Matrix2 m;
			
			m[0][0] = 100.0f;
			m[0][1] = 200.0f;
			m[1][0] = 300.0f;
			m[1][1] = 400.0f;
			float* i = m[0];
			Assert::AreEqual(100.0f, *i);
			Assert::AreEqual(200.0f, *(i+1));
			Assert::AreEqual(100.0f, m[0][0]);
			Assert::AreEqual(200.0f, m[0][1]);
			Assert::AreEqual(300.0f, m[1][0]);
			Assert::AreEqual(400.0f, m[1][1]);
		}
	};
}
