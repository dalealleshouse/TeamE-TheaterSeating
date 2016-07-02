#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/Exceptions.h"
#include "../TheaterSeating/TheaterSales.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;
	const auto epsilon{0.000000001};

	TheaterSales SutFactory()
	{
		auto config{TheaterConfiguration{9.95, 3U, 2U}};
		auto sut{TheaterSales{config}};
		return sut;
	}

	TEST_CLASS(TheaterSales_CalculatePrice_Should)
	{
	public:
		TEST_METHOD(ReturnSeatsTimesPrice)
		{
			const auto expected{29.85};
			auto sut{SutFactory()};
			auto result = sut.CalculatePrice(3);

			Assert::AreEqual(expected, result, epsilon);
		}
	};

	TEST_CLASS(TheaterSales_SellSeats_Should)
	{
	public:
		TEST_METHOD(UpdateTotalSalesAndSeatsSold)
		{
			const auto expected_sales{29.85};
			const auto expected_seats{3U};
			auto sut{SutFactory()};
			sut.SellSeats(1);
			sut.SellSeats(2);

			Assert::AreEqual(expected_sales, sut.TotalSales(), epsilon);
			Assert::AreEqual(expected_seats, sut.SeatsSold());
		}
	};
}
