#pragma once
#include "stdafx.h"
#include "TheaterConfiguration.h"

using std::vector;

namespace theater
{
	struct TheaterSeat;

	class TheaterSeatTracker
	{
		vector<vector<bool>> _seatmatrix;
		TheaterConfiguration _configuration;

		void ThrowIfSeatOutOfBounds(TheaterSeat seat) const;
	public:
		explicit TheaterSeatTracker(TheaterConfiguration configuration);
		bool SeatIsAvailable(TheaterSeat seat) const;
		void ReserveSeat(TheaterSeat seat);
		const vector<vector<bool>> SeatMatrix() const;
		const vector<bool> Row(const unsigned int& row_number) const;
		~TheaterSeatTracker();
	};
}
