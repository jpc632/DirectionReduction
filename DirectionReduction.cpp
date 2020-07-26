#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DirectionReduction
{
	class Test
	{
	public:
		static vector<string> dirReduc(vector<string>& arr)
		{
			for ( unsigned int i = 1; i < arr.size() ; ++i)
			{
				if (arr[i] == "NORTH" && arr[i - 1] == "SOUTH" ||
					arr[i] == "SOUTH" && arr[i - 1] == "NORTH" ||
					arr[i] == "EAST" && arr[i - 1] == "WEST" ||
					arr[i] == "WEST" && arr[i - 1] == "EAST")
				{
					arr.erase(arr.begin() + i - 1, arr.begin() + i + 1);
					i -= i;
				} 
			}
			return arr;
		}
	};



	TEST_CLASS(DirectionReduction)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<string> list = { "NORTH", "SOUTH", "EAST", "WEST" };
			vector<string> result = Test::dirReduc(list);
			
			Assert::AreEqual((size_t)0, result.size());
		}

		TEST_METHOD(TestMethod2)
		{
			vector<string> list = { "NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST" };
			vector<string> result = Test::dirReduc(list);

			Assert::AreEqual((size_t)2, result.size());
		}

		TEST_METHOD(TestMethod3)
		{
			vector<string> list = { "NORTH", "WEST", "SOUTH", "EAST" };
			vector<string> result = Test::dirReduc(list);

			Assert::AreEqual((size_t)4, result.size());
		}


	};
}
