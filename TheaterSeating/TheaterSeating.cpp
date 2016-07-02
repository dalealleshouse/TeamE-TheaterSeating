#include "stdafx.h"
#include "TheaterSeating.h"


namespace theater
{
	using std::make_shared;

	TheaterSeating::TheaterSeating(TheaterConfiguration configuration)
		: _theater_sales{make_shared<TheaterSales>(configuration)}
		  , _theater_seat_tracker{make_shared<TheaterSeatTracker>(configuration)}
	{
	}

	TheaterSeating::~TheaterSeating()
	{
	}
}
