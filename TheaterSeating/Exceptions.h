#pragma once
#include "stdafx.h"
#include "TheaterSeat.h"

namespace theater
{
	using std::string;
	using std::runtime_error;

	class TheaterException :public runtime_error
	{
		explicit TheaterException(const string& _Message)
			: runtime_error(_Message)
		{
		}
	};

	class RowNumberOutOfBoundsException :public runtime_error
	{
	public:
		explicit RowNumberOutOfBoundsException(unsigned int row_number)
			: runtime_error("Row is out of bounds" + std::to_string(row_number))
		{
		};
	};

	class SeatNotAvailableException :public runtime_error
	{
	public:
		explicit SeatNotAvailableException(TheaterSeat seat)
			: runtime_error("Seat is out of bounds: row_number "
				+ std::to_string(seat.row_number)
				+ " seat number "
				+ std::to_string(seat.seat_number))
		{
		}
	};

	class SeatOutOfBoundsException : public runtime_error
	{
	public:
		explicit SeatOutOfBoundsException(TheaterSeat seat)
			: runtime_error("Seat is out of bounds: row_number "
				+ std::to_string(seat.row_number)
				+ " seat number "
				+ std::to_string(seat.seat_number))
		{
		}
	};
}
