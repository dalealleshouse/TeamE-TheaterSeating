#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/CommandFactory.h"
#include "../TheaterSeating/TheaterSeatTracker.h"
#include "../TheaterSeating/TheaterSeating.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;

	CommandFactory SutFactory()
	{
		auto end_program{false};
		auto seating{TheaterSeating{TheaterConfiguration{10.0, 3U, 2U}}};
		auto sut{CommandFactory{seating, end_program}};
		return sut;
	}

	void TestCommandString(string command, string expected_name)
	{
		auto sut{SutFactory()};
		auto result{sut.Build(command)};
		Assert::AreEqual(expected_name, result->Name());
	}

	TEST_CLASS(CommandFactory_Build_Should)
	{
	public:
		TEST_METHOD(BuildExitCommand)
		{
			TestCommandString("exit", "exit");
		}

		TEST_METHOD(IgnoreCase)
		{
			TestCommandString("eXIT", "exit");
		}

		TEST_METHOD(ReturnNotFoundForBadCommands)
		{
			TestCommandString("find_this", "not_found");
		}

		TEST_METHOD(ReturnNotFoundForEmptyCommand)
		{
			TestCommandString("", "not_found");
		}
	};
}
