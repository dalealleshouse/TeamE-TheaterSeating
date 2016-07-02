#include "stdafx.h"
#include "TotalCommand.h"

namespace theater
{
	using std::string;
	using std::stringstream;
	using std::fixed;
	using std::setprecision;

	string TotalCommand::Execute(vector<string> command_arguments)
	{
		stringstream ss{};

		ss << "\tTotal Tickets Sold: " << "\t" << _theater_services.sales.SeatsSold() << "\n";
		ss << "\tTotal Sales: " << "\t\t$" << fixed << setprecision(2)
			<< _theater_services.sales.TotalSales() << "\n";

		return ss.str();
	}

	string TotalCommand::Name()
	{
		return "total";
	}

	string TotalCommand::Description()
	{
		return "Prints the total number of tickets sold and the total amount of money collected.";
	}
}
