#pragma once

namespace theater
{
	struct TheaterSeat
	{
		TheaterSeat(unsigned int row_number, unsigned int seat_number)
			: row_number(row_number),
			  seat_number(seat_number)
		{
		}

		const unsigned int row_number;
		const unsigned int seat_number;
	};
}
