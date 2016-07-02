#pragma once
#include "TheaterCommand.h"

namespace theater
{
	class SeatsCommand :
		public TheaterCommand
	{
	public:
		SeatsCommand(TheaterServices& theater_services, bool& end_program)
			: TheaterCommand(theater_services, end_program)
		{
		}

		string Execute(vector<string> command_arguments) override;
		string Name() override;
		string Description() override;

		~SeatsCommand()
		{
		};
	};
}
