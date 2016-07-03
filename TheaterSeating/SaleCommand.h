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

		static const string invalid_argument_message;
		static const string seat_occupied_message;
		string Execute(vector<string> command_arguments) override;
		string Name() override;
		string Description() override;

		~SaleCommand()
		{
		};
	};
}
