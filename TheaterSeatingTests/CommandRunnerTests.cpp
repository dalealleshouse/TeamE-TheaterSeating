#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/CommandRunner.h"
#include "../TheaterSeating/TheaterConfiguration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CommandRunnerTests
{
	using namespace theater;
	using std::make_unique;

	unique_ptr<CommandRunner> SutFactory(bool& end_program)
	{
		ConfirmFunc cf{ [](const string& s)
		{
			return true;
		} };
		auto config{TheaterConfiguration{10.0, 3U, 2U}};
		auto sut{make_unique<CommandRunner>(config, end_program, cf)};
		return sut;
	}

	TEST_CLASS(CommandRunner_Run_Should)
	{
	public:
		TEST_METHOD(RunExitCommand)
		{
			auto end_program{false};
			auto sut{SutFactory(end_program)};
			sut->Run("exit");
			Assert::IsTrue(end_program);
		}
	};
}
