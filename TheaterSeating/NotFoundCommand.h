#pragma once
#include "TheaterCommand.h"

namespace theater
{
	class NotFoundCommand :
		public TheaterCommand
	{
	public:
		NotFoundCommand(TheaterSeating& theater_seating, bool& end_program)
			: TheaterCommand(theater_seating, end_program)
		{
		}

		string Execute(vector<string> command_arguments) override
		{
			return "Invalid Command, please try again. Type help to see a list of valid commands.";
		};

		string Name() override
		{
			return "not_found";
		};

		string Description() override
		{
			return "Returns if specified command text is not found";
		};

		bool IncludeInHelp() override
		{
			return false;
		};

		~NotFoundCommand()
		{
		};
	};
}
