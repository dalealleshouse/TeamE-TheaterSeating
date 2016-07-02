#pragma once
#include "TheaterCommand.h"

namespace theater
{
	class HelpCommand :
		public TheaterCommand
	{
	public:
		HelpCommand(TheaterServices& theater_services, bool& end_program)
			: TheaterCommand(theater_services, end_program)
		{
		}

		string Execute(vector<string> command_arguments) override;
		string Name() override;
		string Description() override;

		~HelpCommand()
		{
		};
	};
}
