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
			seat.row_number > _configuration.number_of_rows ||
			seat.seat_number > _configuration.searts_per_row)
			throw SeatOutOfBoundsException(seat);
	}

	TheaterSeatTracker::TheaterSeatTracker(TheaterConfiguration configuration)
		: _seatmatrix(configuration.number_of_rows, vector<bool>(configuration.searts_per_row, false)),
		  _configuration{configuration}
	{
	}

	bool TheaterSeatTracker::SeatIsAvailable(TheaterSeat seat) const
	{
		ThrowIfSeatOutOfBounds(seat);
		return !_seatmatrix[seat.row_number - 1][seat.seat_number - 1];
	}

	void TheaterSeatTracker::ReserveSeat(TheaterSeat seat)
	{
		ThrowIfSeatOutOfBounds(seat);
		if (!SeatIsAvailable(seat))
			throw SeatNotAvailableException{seat};

		_seatmatrix[seat.row_number - 1][seat.seat_number - 1] = true;
	}

	const vector<vector<bool>> TheaterSeatTracker::SeatMatrix() const
	{
		return _seatmatrix;
	}

	const vector<bool> TheaterSeatTracker::Row(const unsigned int& row_number) const
	{
		if (row_number == 0 || row_number > _configuration.number_of_rows)
			throw RowNumberOutOfBoundsException{row_number};

		return _seatmatrix[row_number - 1];
	}

	TheaterSeatTracker::~TheaterSeatTracker()
	{
	}
}
