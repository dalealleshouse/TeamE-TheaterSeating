#pragma once
#include "stdafx.h"
#include "TheaterSeat.h"

namespace theater
{
	using std::string;
	using std::runtime_error;

	class TheaterException :public runtime_error
	{
	protected:
		explicit TheaterException(const string& _Message)
			: runtime_error(_Message)
		{
		}
	};

	class RowNumberOutOfBoundsException :public TheaterException
	{
	public:
		explicit RowNumberOutOfBoundsException(unsigned int row_number)
			: TheaterException("Row is out of bounds" + std::to_string(row_number))
		{
		};
	};

	class SeatNotAvailableException :public TheaterException
	{
	public:
		explicit SeatNotAvailableException(TheaterSeat seat)
			: TheaterException("Seat is out of bounds: row_number "
				+ std::to_string(seat.row_number)
				+ " seat number "
				+ std::to_string(seat.seat_number))
		{
		}
	};

	class SeatOutOfBoundsException : public TheaterException
	{
	public:
		explicit SeatOutOfBoundsException(TheaterSeat seat)
			: TheaterException("Seat is out of bounds: row_number "
				+ std::to_string(seat.row_number)
				+ " seat number "
				+ std::to_string(seat.seat_number))
		{
		}
	};
}
