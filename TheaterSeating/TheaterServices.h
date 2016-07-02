#pragma once
#include "TheaterSeatTracker.h"
#include "TheaterSales.h"

namespace theater {
	struct TheaterServices
	{
		TheaterServices(const TheaterSeatTracker& tracker, const TheaterSales& sales)
			: tracker(tracker),
			  sales(sales)
		{
		}

		TheaterSeatTracker tracker;
		TheaterSales sales;
	};
}
