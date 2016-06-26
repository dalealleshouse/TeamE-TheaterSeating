#pragma once

namespace theater
{
	struct TheaterSeat
	{
		TheaterSeat(int row_number, int seat_number)
			: row_number(row_number),
			  seat_number(seat_number)
		{
		}

		const int row_number;
		const int seat_number;
	};
}
