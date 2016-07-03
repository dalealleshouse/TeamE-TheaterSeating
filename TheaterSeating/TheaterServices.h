#pragma once
#include "TheaterSeatTracker.h"
#include "TheaterSales.h"
#include "TheaterCommand.h"

namespace theater
{
	using std::string;
	typedef bool(*ConfirmFunc)(const string& confirm_message);

	struct TheaterServices
	{
		explicit TheaterServices(const TheaterConfiguration config, ConfirmFunc confirm)
			: tracker{TheaterSeatTracker{config}},
			  sales{TheaterSales{config}},
			  config{config},
			  confirm{confirm}
		{
		}

		TheaterSeatTracker tracker;
		TheaterSales sales;
		TheaterConfiguration config;
		ConfirmFunc confirm;
	};
}
