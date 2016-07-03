#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheaterSeating/TheaterSeatTracker.h"
#include "../TheaterSeating/TheaterSeat.h"
#include "../TheaterSeating/Exceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheaterSeatingTests
{
	using namespace theater;

	TheaterSeatTracker SutFactory()
	{
		auto config{TheaterConfiguration{10.0, 3U, 2U}};
		auto sut{TheaterSeatTracker{config}};
		return sut;
	}

	TEST_CLASS(TheaterSeatTracker_SeatsAvailable_Should)
	{
	public:
		TEST_METHOD(ThrowIfRowNumberOutOfBounds)
		{
			auto sut{SutFactory()};

			Assert::ExpectException<RowNumberOutOfBoundsException>([&sut]()
				{
					sut.SeatsAvailable(20);
				}
			);
		}

		TEST_METHOD(ReturnSeatsIfAllAreOpenInRow)
		{
			const auto expected{ 3U };
			auto sut{ SutFactory() };

			Assert::AreEqual(expected, sut.SeatsAvailable(2));
		}

		TEST_METHOD(ReturnSeatsIfSomeAreOpenInRow)
		{
			const auto expected{ 1U };
			auto sut{ SutFactory() };
			sut.ReserveSeat(TheaterSeat{ 2,1 });
			sut.ReserveSeat(TheaterSeat{ 2,2 });

			Assert::AreEqual(expected, sut.SeatsAvailable(2));
		}

		TEST_METHOD(ReturnSeatsIfAllAreOpen)
		{
			const auto expected{ 6U };
			auto sut{ SutFactory() };

			Assert::AreEqual(expected, sut.SeatsAvailable());
		}

		TEST_METHOD(ReturnSeatsIfSomeAreOpen)
		{
			const auto expected{ 4U };
			auto sut{ SutFactory() };
			sut.ReserveSeat(TheaterSeat{ 2,1 });
			sut.ReserveSeat(TheaterSeat{ 2,2 });

			Assert::AreEqual(expected, sut.SeatsAvailable());
		}
	};

	TEST_CLASS(TheaterSeatTracker_SeatMatrix_Should)
	{
	public:
		TEST_METHOD(ReturnIntializedSeatMatrix)
		{
			auto sut{SutFactory()};
			auto result = sut.SeatMatrix();

			Assert::AreEqual(2U, result.size());

			for (auto r : result)
			{
				Assert::AreEqual(3U, r.size());

				for (auto s : r)
					Assert::IsFalse(s);
			}
		}
	};

	TEST_CLASS(TheaterSeatTracker_SeatIsAvailable_Should)
	{
	public:
		TEST_METHOD(ThrowIfSeatOutOfBounds)
		{
			auto sut{SutFactory()};

			Assert::ExpectException<SeatOutOfBoundsException>([&sut]()
				{
					sut.SeatIsAvailable(TheaterSeat{0,0});
				}
			);
		}

		TEST_METHOD(ReturnTrueIfSeatIsAvailable)
		{
			auto sut{SutFactory()};

			Assert::IsTrue(sut.SeatIsAvailable(TheaterSeat{1,1}));
		}

		TEST_METHOD(ReturnFalseIfSeatIsNotAvailable)
		{
			auto seat{TheaterSeat{1,1}};
			auto sut{SutFactory()};

			sut.ReserveSeat(seat);
			Assert::IsFalse(sut.SeatIsAvailable(seat));
		}
	};

	TEST_CLASS(TheaterSeatTracker_ReserveSeat_Should)
	{
	public:
		TEST_METHOD(ThrowIfSeatOutOfBounds)
		{
			auto sut{SutFactory()};

			sut.ReserveSeat(TheaterSeat{1,1});
			Assert::ExpectException<SeatOutOfBoundsException>([&sut]()
				{
					sut.ReserveSeat(TheaterSeat{10,1});
				}
			);
		}

		TEST_METHOD(ThrowIfSeatNotAvailable)
		{
			auto sut{SutFactory()};

			sut.ReserveSeat(TheaterSeat{1,1});
			Assert::ExpectException<SeatNotAvailableException>([&sut]()
				{
					sut.ReserveSeat(TheaterSeat{1,1});
				}
			);
		}

		TEST_METHOD(ReserveSeat)
		{
			const auto seat{TheaterSeat{1,1}};
			auto sut{SutFactory()};

			sut.ReserveSeat(TheaterSeat{1,1});
			Assert::IsFalse(sut.SeatIsAvailable(seat));
		}
	};

	TEST_CLASS(TheaterSeatTracker_Row_Should)
	{
	public:
		TEST_METHOD(ThorwIfRowOutOfBounds)
		{
			auto sut{SutFactory()};

			Assert::ExpectException<RowNumberOutOfBoundsException>([sut]()
				{
					sut.Row(5);
				}
			);
		}

		TEST_METHOD(ReturnRequestedRow)
		{
			auto sut{SutFactory()};

			sut.ReserveSeat(TheaterSeat{2,1});
			auto result{sut.Row(2)};
			Assert::IsTrue(result[0]);
			Assert::IsFalse(result[1]);
			Assert::IsFalse(result[2]);
		}
	};
}
