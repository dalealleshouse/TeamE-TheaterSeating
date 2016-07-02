#pragma once
#include "TheaterCommand.h"

namespace theater
{
	class SaleCommand :
		public TheaterCommand
	{
	public:
		SaleCommand(TheaterServices& theater_services, bool& end_program)
			: TheaterCommand(theater_services, end_program)
		{
		}

		string Execute(vector<string> command_arguments) override;
		string Name() override;
		string Description() override;

		~SaleCommand()
		{
		};
	};
}
