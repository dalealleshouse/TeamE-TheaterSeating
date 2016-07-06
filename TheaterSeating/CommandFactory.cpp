#include "stdafx.h"
#include "CommandFactory.h"
#include "ExitCommand.h"
#include "TheaterCommand.h"
#include "NotFoundCommand.h"
#include "HelpCommand.h"
#include "TotalCommand.h"
#include "SeatsCommand.h"
#include "SeatChartCommand.h"
#include "SaleCommand.h"

namespace theater
{
	using std::shared_ptr;
	using std::make_shared;
	using std::transform;
	using std::map;
	using std::make_pair;


	CommandFactory::CommandFactory(TheaterServices& theater_services, bool& end_program)
		: _theater_services{theater_services}, _end_program{end_program}
	{
	}

	shared_ptr<TheaterCommand> CommandFactory::Build(string command)
	{
		transform(command.begin(), command.end(), command.begin(), tolower);
		auto& commands{Commands()};

		auto iter = commands.find(command);

		if (iter != commands.end())
			return iter->second;

		return _not_found_command;
	}

	void CommandFactory::PushCommand(shared_ptr<TheaterCommand>& cmd)
	{
		_commands.emplace(make_pair(cmd->Name(), cmd));
	}

	const map<string, shared_ptr<TheaterCommand>>& CommandFactory::Commands()
	{
		if (_commands.empty())
		{
			// Ideally, these would be read in via some type of reflection but I don't
			// have time to figure out how to do that in C++
			shared_ptr<TheaterCommand> ex{new ExitCommand{_theater_services, _end_program}};
			PushCommand(ex);

			shared_ptr<TheaterCommand> help{new HelpCommand{_theater_services, _end_program}};
			_commands.emplace(make_pair(help->Name(), help));
			PushCommand(help);

			shared_ptr<TheaterCommand> sale{new SaleCommand{_theater_services, _end_program}};
			PushCommand(sale);

			shared_ptr<TheaterCommand> seatschart{new SeatChartCommand{_theater_services, _end_program}};
			PushCommand(seatschart);

			shared_ptr<TheaterCommand> seats{new SeatsCommand{_theater_services, _end_program}};
			PushCommand(seats);

			shared_ptr<TheaterCommand> total{new TotalCommand{_theater_services, _end_program}};
			PushCommand(total);

			shared_ptr<TheaterCommand> nf{new NotFoundCommand{_theater_services, _end_program}};
			_not_found_command = nf;
		}

		return _commands;
	}

	CommandFactory::~CommandFactory()
	{
	}
}
