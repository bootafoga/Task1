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

	TEST_METHOD(At_CorrectIndex)
	{
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		Assert::AreEqual(lst.At(1), 2);
	}

	TEST_METHOD(At_NegativeIndex)
	{
		try {
			lst.At(-1);
		}
		catch (std::out_of_range exp) {
			Assert::AreEqual("Index must be >= 0", exp.what());
		}

	}

	TEST_METHOD(At_BiggerThanSizeIndex)
	{
		try {
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.At(10);
		}
		catch (std::out_of_range exp) {
			Assert::AreEqual("Index is larger than size of list", exp.what());
		}

	}

	TEST_METHOD(CorrectIndex_PushFront)
	{
		lst.push_front(1);
		lst.push_front(2);
		lst.push_front(3);
		Assert::AreEqual(lst.At(1), 2);
	}

	TEST_METHOD(IncorrectIndex_PushFront)
	{
		try {
			lst.At(-1);
		}
		catch (std::out_of_range exp) {
			Assert::AreEqual("Index must be >= 0", exp.what());
		}

	}


};