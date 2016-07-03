#include "stdafx.h"
#include "SeatChartCommand.h"
#include "TheaterSeat.h"

namespace theater
{
	using std::stringstream;
	using std::setw;
	using std::endl;
	using std::to_string;

	string SeatChartCommand::Execute(vector<string> command_arguments)
	{
		const auto kWidth{5U};
		const auto kOffset{5U};
		auto& seat_matrix{_theater_services.tracker.SeatMatrix()};
		stringstream ss{};

		ss << setw(kWidth + kOffset) << "";

		for (auto i{1U}; i <= _theater_services.config.searts_per_row; i++)
			ss << setw(kWidth) << i;

		ss << endl;

		auto row_number{0U};
		for (const auto& r : seat_matrix)
		{
			ss << setw(kWidth + kOffset) << "R" + to_string(++row_number);

			for (const auto& s : r)
			{
				auto occupied = s ? '*' : '#';
				ss << setw(kWidth) << occupied;
			}

			ss << endl;
		}

		return ss.str();
	}

	string SeatChartCommand::Name()
	{
		return "seatchart";
	}

	string SeatChartCommand::Description()
	{
		return "Displays available seats in a matrix with a * character representing an occupied seat "
			"and a # character representing an open seat";
	}
}
