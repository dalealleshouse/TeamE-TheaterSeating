#pragma once

namespace theater
{
	struct TheaterConfiguration
	{
		TheaterConfiguration(double price_per_seat, unsigned searts_per_row, unsigned number_of_rows)
			: price_per_seat(price_per_seat),
			  searts_per_row(searts_per_row),
			  number_of_rows(number_of_rows)
		{
		}
		
		const double price_per_seat;
		const unsigned int searts_per_row;
		const unsigned int number_of_rows;
	};
}
