#pragma once
#include "TheaterSales.h"
#include "TheaterSeatTracker.h"

namespace theater
{
	using std::shared_ptr;

	class TheaterSeating
	{
		shared_ptr<TheaterSales> _theater_sales;
		shared_ptr<TheaterSeatTracker> _theater_seat_tracker;
	public:
		explicit TheaterSeating(TheaterConfiguration configuration);
		~TheaterSeating();
	};
}
