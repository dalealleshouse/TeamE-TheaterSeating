#include "stdafx.h"
#include "SeatsCommand.h"

namespace theater
{
	using std::stringstream;
	using std::invalid_argument;
	using std::stoi;

	string SeatsCommand::InvalidArgument() const
	{
		stringstream ss{};

		ss << "Invalid Arguments. Valid arguments are nothing or a digit beetween 1 and "
			<< _theater_services.config.number_of_rows;

		return ss.str();
	}

	string SeatsCommand::Execute(vector<string> command_arguments)
	{
		if (command_arguments.size() > 1)
			return InvalidArgument();

		stringstream ss{};

		ss << "Seats Available ";

		if (command_arguments.size() == 0)
		{
			ss << ":" << _theater_services.tracker.SeatsAvailable();
			return ss.str();
		}

		unsigned int row_number;
		try
		{
			row_number = stoi(command_arguments[0]);
		}
		catch (invalid_argument&)
		{
			return InvalidArgument();
		}


		ss << "R"
			<< row_number
			<< ":"
			<< _theater_services.tracker.SeatsAvailable(stoi(command_arguments[0]));
		return ss.str();
	}

	string SeatsCommand::Name()
	{
		return "seats";
	}

	string SeatsCommand::Description()
	{
		return "Displays the total number seats available in the specified "
			"row or total seats available in the theater if row_number is omitted";
	}
}
