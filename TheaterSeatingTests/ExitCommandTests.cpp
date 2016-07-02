#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/ExitCommand.h"
#include "../TheaterSeating/TheaterCommand.h"
#include "../TheaterSeating/TheaterConfiguration.h"
#include "../TheaterSeating/TheaterSeating.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;

	TEST_CLASS(ExitCommand_Execute_Should)
	{
	public:
		TEST_METHOD(SetExitProgramToTrue)
		{
			auto ts{TheaterSeating{TheaterConfiguration{0.0,0U,0U}}};
			auto end_program{false};
			TheaterCommand* sut{new ExitCommand{ts, end_program}};
			sut->Execute();
			delete sut;
			Assert::IsTrue(end_program);
		}
	};
}
