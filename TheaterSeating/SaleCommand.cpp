#include "stdafx.h"
#include "SaleCommand.h"
#include "TheaterSeat.h"
#include "Exceptions.h"

namespace theater
{
	using std::stringstream;
	using std::to_string;

	const string SaleCommand::invalid_argument_message{
		"Invalid argument(s) Please enter a comma seperated list of row seat number. eg 1 2, 1 3"};

	const string SaleCommand::seat_occupied_message{
		" Not Avaialible"};

	TheaterSeat BuildSeat(string command_argument)
	{
		stringstream ss{command_argument};

		auto seat_number{0U};
		auto row_number{0U};


		ss >> row_number;
		if (ss.fail())
			throw SaleCommand::invalid_argument_message;

		ss >> seat_number;
		if (ss.fail())
			throw SaleCommand::invalid_argument_message;

		return TheaterSeat{row_number, seat_number};
	}

	string SaleCommand::Execute(vector<string> command_arguments)
	{
		if (command_arguments.size() == 0)
			return invalid_argument_message;

		vector<TheaterSeat> seats{};
		for (auto& arg:command_arguments)
		{
			try
			{
				seats.push_back(BuildSeat(arg));
			}
			catch (string&)
			{
				return invalid_argument_message;
			}
		}

		for (auto& s:seats)
		{
			try
			{
				if (!_theater_services.tracker.SeatIsAvailable(s))
					return to_string(s.row_number) + " " + to_string(s.seat_number) + seat_occupied_message;
			}
			catch (const TheaterException&)
			{
				return invalid_argument_message;
			}
		}

		return "";
	}

	string SaleCommand::Name()
	{
		return "sale";
	}

	string SaleCommand::Description()
	{
		return "Reserves seats after verification of money received. Accepts a comma delimited list of row number seat number (eg: 1 5,1 6)";
	}
}
