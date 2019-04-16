#include "stdafx.h"
#include "CppUnitTest.h"
extern int  GetMaxAddOfArray(int* arr, int subs);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int* array = {};
			int subs = sizeof(array) / sizeof(array[0]);
			int MAX = GetMaxAddOfArray(array, subs);
			Assert::AreEqual(MAX, 0);
		}
		TEST_METHOD(TestMethod2)
		{
			int array[] = { -2,11,-4,13,-5,-2 };
			int subs = sizeof(array) / sizeof(array[0]);
			int MAX = GetMaxAddOfArray(array, subs);
			Assert::AreEqual(MAX, 20);
		}
		TEST_METHOD(TestMethod3)
		{
			int array[] = { -2,-11,-4,-13,-5,-2 };
			int subs = sizeof(array) / sizeof(array[0]);
			int MAX = GetMaxAddOfArray(array, subs);
			Assert::AreEqual(MAX, 0);
		}
		TEST_METHOD(TestMethod4)
		{
			int array[] = { 1,4,7 };
			int subs = sizeof(array) / sizeof(array[0]);
			int MAX = GetMaxAddOfArray(array, subs);
			Assert::AreEqual(MAX, 12);
		}


	};
}