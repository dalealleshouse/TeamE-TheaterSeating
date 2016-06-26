#include "stdafx.h"
#include "TheaterSeatTracker.h"
#include "TheaterSeat.h"
#include "Exceptions.h"

namespace theater
{
	void TheaterSeatTracker::ThrowIfSeatOutOfBounds(TheaterSeat seat) const
	{
		if (seat.row_number <= 0 ||
			seat.seat_number <= 0 ||
			seat.row_number > configuration_.number_of_rows ||
			seat.seat_number > configuration_.searts_per_row)
			throw SeatOutOfBoundsException(seat);
	}

	TheaterSeatTracker::TheaterSeatTracker(TheaterConfiguration configuration)
		: seatmatrix_(configuration.number_of_rows, vector<bool>(configuration.searts_per_row, false)),
		  configuration_{configuration}
	{
	}

	TheaterSeatTracker::~TheaterSeatTracker()
	{
	}

	bool TheaterSeatTracker::SeatIsAvailable(TheaterSeat seat) const
	{
		ThrowIfSeatOutOfBounds(seat);
		return !seatmatrix_[seat.row_number - 1][seat.seat_number - 1];
	}

	void TheaterSeatTracker::ReserveSeat(TheaterSeat seat)
	{
		ThrowIfSeatOutOfBounds(seat);
		if (!SeatIsAvailable(seat))
			throw SeatNotAvailableException{seat};

		seatmatrix_[seat.row_number - 1][seat.seat_number - 1] = true;
	}

	const vector<vector<bool>> TheaterSeatTracker::SeatMatrix() const
	{
		return seatmatrix_;
	}

	const vector<bool> TheaterSeatTracker::Row(const unsigned int& row_number) const
	{
		if (row_number == 0 || row_number > configuration_.number_of_rows)
			throw RowNumberOutOfBoundsException{row_number};

		return seatmatrix_[row_number - 1];
	}
}
