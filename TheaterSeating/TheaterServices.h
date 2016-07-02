#pragma once
#include "TheaterSeatTracker.h"
#include "TheaterSales.h"

namespace theater
{
	struct TheaterServices
	{
		explicit TheaterServices(const TheaterConfiguration config)
			: tracker{TheaterSeatTracker{config}},
			  sales{TheaterSales{config}}
		{
		}

		TheaterSeatTracker tracker;
		TheaterSales sales;
	};
}
