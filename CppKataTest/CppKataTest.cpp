#include "pch.h"
#include "CppUnitTest.h"

#include <vector>

#include "CppKataPractice.h"

// Test framework API
// https://github.com/MicrosoftDocs/visualstudio-docs/blob/master/docs/test/microsoft-visualstudio-testtools-cppunittestframework-api-reference.md

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppKataTest
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2019/11/06")
	END_TEST_MODULE_ATTRIBUTE()

	TEST_MODULE_INITIALIZE(ModuleInitialize)
	{
		Logger::WriteMessage("In Module Initialize");
	}

	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("In Module Cleanup");
	}

	TEST_CLASS(CppKataTest_KarateChop)
	{
	public:

		CppKataTest_KarateChop()
		{
			Logger::WriteMessage("In CppKataTest_KarateChop");
		}

		~CppKataTest_KarateChop()
		{
			Logger::WriteMessage("In ~CppKataTest_KarateChop");
		}

		TEST_CLASS_INITIALIZE(CppKataTest_KarateChop_ClassInitialize)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Class Initialize");
		}

		TEST_CLASS_CLEANUP(CppKataTest_KarateChop_ClassCleanup)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Class Cleanup");
		}

		TEST_METHOD_INITIALIZE(CppKataTest_KarateChop_MethodInitialize)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Method Initialize");
		}

		TEST_METHOD_CLEANUP(CppKataTest_KarateChop_MethodCleanup)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Method Cleanup");
		}

		TEST_METHOD(KarateChop_SearchAnEmptyArray)
		{
			int NumberToSearch = 10;
			int ArrayToSearch[10];

			int result = kata_practice::ChopAndFindNumber(NumberToSearch, ArrayToSearch, 0);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(KarateChop_UnsuccessSearchOneElementArray)
		{
			int NumberToSearch = 10;
			int ArrayToSearch[10] = {1};

			int result = kata_practice::ChopAndFindNumber(NumberToSearch, ArrayToSearch, 1);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(KarateChop_SuccessSearchOneElementArray)
		{
			int NumberToSearch = 2;
			int ArrayToSearch[10] = { 2 };

			int result = kata_practice::ChopAndFindNumber(NumberToSearch, ArrayToSearch, 1);
			Assert::AreEqual(0, result);
		}

		TEST_METHOD(KarateChop_UnsuccessSearchOddLengthArray)
		{
			int NumberToSearch = 5;
			int ArrayToSearch[10] = { 2, 6, 8 };

			int result = kata_practice::ChopAndFindNumber(NumberToSearch, ArrayToSearch, 3);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(KarateChop_SuccessSearchOddLengthArray)
		{
			constexpr int ArrayLength = 7;
			int ArrayToSearch[ArrayLength] = { -50, -34, 0, 2, 6, 8, 10032 };

			for (int i = 0; i < ArrayLength; i++)
			{
				int result = kata_practice::ChopAndFindNumber(ArrayToSearch[i], ArrayToSearch, ArrayLength);
				Assert::AreEqual(i, result);
			}
		}

		TEST_METHOD(KarateChop_UnsuccessSearchEvenLengthArray)
		{
			int NumberToSearch = 5;
			constexpr int ArrayLength = 4;
			int ArrayToSearch[ArrayLength] = { 2, 6, 8, 24 };

			int result = kata_practice::ChopAndFindNumber(NumberToSearch, ArrayToSearch, ArrayLength);
			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(KarateChop_SuccessSearchEvenLengthArray)
		{
			constexpr int ArrayLength = 6;
			int ArrayToSearch[ArrayLength] = { -34, 0, 2, 6, 8, 10032 };

			for (int i = 0; i < ArrayLength; i++)
			{
				int result = kata_practice::ChopAndFindNumber(ArrayToSearch[i], ArrayToSearch, ArrayLength);
				Assert::AreEqual(i, result);
			}
		}
	};
}


/*
Minimal Test Class Template

namespace CppKataTest
{
	BEGIN_TEST_MODULE_ATTRIBUTE()
		TEST_MODULE_ATTRIBUTE(L"Date", L"2019/11/06")
		END_TEST_MODULE_ATTRIBUTE()

		TEST_MODULE_INITIALIZE(ModuleInitialize)
	{
		Logger::WriteMessage("In Module Initialize");
	}

	TEST_MODULE_CLEANUP(ModuleCleanup)
	{
		Logger::WriteMessage("In Module Cleanup");
	}

	TEST_CLASS(CppKataTest_KarateChop)
	{
	public:

		CppKataTest_KarateChop()
		{
			Logger::WriteMessage("In CppKataTest_KarateChop");
		}

		~CppKataTest_KarateChop()
		{
			Logger::WriteMessage("In ~CppKataTest_KarateChop");
		}

		TEST_CLASS_INITIALIZE(CppKataTest_KarateChop_ClassInitialize)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Class Initialize");
		}

		TEST_CLASS_CLEANUP(CppKataTest_KarateChop_ClassCleanup)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Class Cleanup");
		}

		TEST_METHOD_INITIALIZE(CppKataTest_KarateChop_MethodInitialize)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Method Initialize");
		}

		TEST_METHOD_CLEANUP(CppKataTest_KarateChop_MethodCleanup)
		{
			Logger::WriteMessage("In CppKataTest_KarateChop Method Cleanup");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(KarateChop_Simple01)
			TEST_OWNER(L"NamTserof")
			TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(KarateChop_Simple01)
		{
			Logger::WriteMessage("In KarateChop_Simple01");
			Assert::AreEqual(0, 0);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(KarateChop_Simple02)
			TEST_IGNORE()
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(KarateChop_Simple02)
		{
			Logger::WriteMessage("In KarateChop_Simple02");
			Assert::Fail(L"Fail");
		}
	};

}

*/