#include "stdafx.h"
#include "TheaterSales.h"

namespace theater
{
	TheaterSales::TheaterSales(TheaterConfiguration configuration)
		: _configuration{configuration}
	{
	}

	double TheaterSales::CalculatePrice(int number_of_seats) const
	{
		return number_of_seats * _configuration.price_per_seat;
	}

	unsigned int TheaterSales::SeatsSold() const
	{
		return _seats_sold;
	}

	double TheaterSales::TotalSales() const
	{
		return _total_sales;
	}

	void TheaterSales::SellSeats(int number_of_seats)
	{
		_seats_sold += number_of_seats;
		_total_sales += CalculatePrice(number_of_seats);
	}
}
