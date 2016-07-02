#pragma once
#include "TheaterCommand.h"

namespace theater
{
	class ExitCommand :
		public TheaterCommand
	{
	public:

		ExitCommand(TheaterSeating& theater_seating, bool& end_program)
			: TheaterCommand(theater_seating, end_program)
		{
		}

		string Execute(vector<string> command_arguments) override
		{
			_end_program = true;
			return "Thank you for using the ACME theater seating program.";
		};

		string Name() override
		{
			return "exit";
		};

		string Description() override
		{
			return "Ends and exits the program";
		};

		~ExitCommand()
		{
		};
	};
}
