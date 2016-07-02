#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/CommandTextParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;

	TEST_CLASS(CommandTextParser_Parse_Should)
	{
	private:
		void CommandTextAreEqual(const CommandText& expected, const CommandText& actual)
		{
			Assert::AreEqual(expected.command, actual.command);
			Assert::AreEqual(expected.arguments.size(), actual.arguments.size());

			for (unsigned int i{}; i < expected.arguments.size(); i++)
			{
				Assert::AreEqual(expected.arguments[i], actual.arguments[i]);
			}
		}

		void TestCommandText(const string& text, const CommandText& expected)
		{
			auto sut{CommandTextParser{}};

			auto result = sut.Parse(text);

			CommandTextAreEqual(expected, result);
		}

	public:
		TEST_METHOD(ParseCommand)
		{
			TestCommandText("some_command", CommandText{"some_command", vector<string>{}});
		}

		TEST_METHOD(ParseArgumentsByComma)
		{
			TestCommandText(
				"some_command with, some, arguments",
				CommandText{"some_command", vector<string>{"with", "some", "arguments"}});
		}

		TEST_METHOD(ParseArgumentsWithSpacesByComma)
		{
			TestCommandText(
				"some_command with some, arguments",
				CommandText{"some_command", vector<string>{"with some", "arguments"}});
		}
	};
}
