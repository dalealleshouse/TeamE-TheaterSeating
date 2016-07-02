#pragma once
#include "TheaterConfiguration.h"

namespace theater
{
	class TheaterSales
	{
		TheaterConfiguration _configuration;
		unsigned int _seats_sold{};
		double _total_sales{};
	public:
		explicit TheaterSales(TheaterConfiguration configuration);
		double CalculatePrice(int seat) const;
		unsigned int SeatsSold() const;
		double TotalSales() const;
		void SellSeats(int number_of_seats);
	};
}
