#include "stdafx.h"
#include "TheaterSeatTracker.h"
#include "TheaterSeat.h"
#include "Exceptions.h"

namespace theater
{
	using std::accumulate;

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

	unsigned int SumRow(vector<bool>& row)
	{
		auto count{0U};
		for (auto& b : row)
			if (!b) ++count;

		return count;
	}

	unsigned TheaterSeatTracker::SeatsAvailable() const
	{
		auto count{0U};
		for (auto r : _seatmatrix)
			count += SumRow(r);

		return count;
	}

	unsigned TheaterSeatTracker::SeatsAvailable(const unsigned int& row_number) const
	{
		auto row{Row(row_number)};
		return SumRow(row);
	}

	bool TheaterSeatTracker::SeatIsAvailable(const TheaterSeat& seat) const
	{
		ThrowIfSeatOutOfBounds(seat);
		return !_seatmatrix[seat.row_number - 1][seat.seat_number - 1];
	}

	void TheaterSeatTracker::ReserveSeat(const TheaterSeat& seat)
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
