#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LabOne/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	
	TEST_CLASS(ListTest)
	{
	public:
		
		List<int> lst;

		TEST_METHOD_INITIALIZE(TestMethod1)
		{
			
		}

		TEST_METHOD_CLEANUP(cleanUp)
		{
				
		}

		TEST_METHOD(At_correct_index) //push back
		{
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			Assert::AreEqual(lst.At(1), 2);
		}

		TEST_METHOD(At_incorrect_index) //push back
		{
			try {
				lst.At(-1);
			}
			catch (std::out_of_range exp) {
				Assert::AreEqual("Index must be >= 0", exp.what());
			}

		}


	};
