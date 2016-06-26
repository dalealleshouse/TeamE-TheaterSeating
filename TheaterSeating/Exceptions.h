#pragma once
#include "stdafx.h"
#include "TheaterSeat.h"

namespace theater
{
	class TheaterException :public std::runtime_error
	{
		explicit TheaterException(const std::string& _Message)
			: runtime_error(_Message)
		{
		}
	};

	class RowNumberOutOfBoundsException :public std::runtime_error
	{
	public:
		explicit RowNumberOutOfBoundsException(unsigned int row_number)
			: runtime_error("Row is out of bounds" + std::to_string(row_number))
		{
		};
	};

	class SeatNotAvailableException :public std::runtime_error
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

	class SeatOutOfBoundsException : public std::runtime_error
	{
	public:
		SeatOutOfBoundsException(TheaterSeat seat)
			: runtime_error("Seat is out of bounds: row_number "
				+ std::to_string(seat.row_number)
				+ " seat number "
				+ std::to_string(seat.seat_number))
		{
		}
	};
}
