#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/SaleCommand.h"
#include "../TheaterSeating/ExitCommand.h"
#include "../TheaterSeating/TheaterSeat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;
	using std::shared_ptr;

	TEST_CLASS(SaleCommand_Execute_Should)
	{
		TheaterServices* _services;
		TheaterCommand* _sut;

	public:
		TEST_METHOD_INITIALIZE(SaleCommand_Execute_Should_Init)
		{
			_services = new TheaterServices{TheaterConfiguration{10.0,5U,5U}};
			_services->tracker.ReserveSeat(TheaterSeat{1,1});
			auto end_program{false};
			_sut = new SaleCommand{*_services, end_program};
		}

		TEST_METHOD_CLEANUP(SaleCommand_Execute_Should_Cleanup)
		{
			delete _services;
			_services = nullptr;

			delete _sut;
			_sut = nullptr;
		}

		TEST_METHOD(ReturnInvalidMessageIfNoArguments)
		{
			auto result{_sut->Execute(vector<string>{})};
			Assert::AreEqual(SaleCommand::invalid_argument_message, result);
		}

		TEST_METHOD(ReturnInvalidMessageIfBadArguments)
		{
			auto result{_sut->Execute(vector<string>{"1 3", "foo"})};
			Assert::AreEqual(SaleCommand::invalid_argument_message, result);
		}

		TEST_METHOD(ReturnInvalidMessageIfSeatOutOfRange)
		{
			auto result{_sut->Execute(vector<string>{"6 3"})};
			Assert::AreEqual(SaleCommand::invalid_argument_message, result);
		}

		TEST_METHOD(ReturnSeatNotAvailable)
		{
			auto expected{"1 1" + SaleCommand::seat_occupied_message};
			auto result{_sut->Execute(vector<string>{"1 1"})};
			Assert::AreEqual(expected, result);
		}
	};
}
