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
		unsigned int SeatsAvailable() const;
		unsigned int SeatsAvailable(const unsigned int& row_number) const;
		bool SeatIsAvailable(const TheaterSeat& seat) const;
		void ReserveSeat(const TheaterSeat& seat);
		const vector<vector<bool>> SeatMatrix() const;
		const vector<bool> Row(const unsigned int& row_number) const;
		~TheaterSeatTracker();
	};
}
