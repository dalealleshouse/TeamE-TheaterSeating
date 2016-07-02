#include "stdafx.h"
#include "CommandFactory.h"
#include "ExitCommand.h"
#include "TheaterCommand.h"
#include "NotFoundCommand.h"
#include "HelpCommand.h"
#include "TotalCommand.h"

namespace theater
{
	using std::shared_ptr;
	using std::make_shared;
	using std::transform;

	CommandFactory::CommandFactory(TheaterServices& theater_services, bool& end_program)
		: _theater_services{theater_services}, _end_program{end_program}
	{
	}

	shared_ptr<TheaterCommand> CommandFactory::Build(string command)
	{
		transform(command.begin(), command.end(), command.begin(), tolower);
		auto& commands{Commands()};

		for (auto& cmd : commands)
			if (cmd->Name() == command)
				return cmd;

		return _not_found_command;
	}

	const vector<shared_ptr<TheaterCommand>>& CommandFactory::Commands()
	{
		if (_commands.size() == 0)
		{
			// Ideally, these would be read in via some type of reflection but I don't
			// have time to figure out how to do that in C++
			shared_ptr<TheaterCommand> ex{new ExitCommand{_theater_services, _end_program}};
			_commands.push_back(ex);

			shared_ptr<TheaterCommand> help{new HelpCommand{_theater_services, _end_program}};
			_commands.push_back(help);

			shared_ptr<TheaterCommand> total{new TotalCommand{_theater_services, _end_program}};
			_commands.push_back(total);

			shared_ptr<TheaterCommand> nf{new NotFoundCommand{_theater_services, _end_program}};
			_not_found_command = nf;
		}

		return _commands;
	}

	CommandFactory::~CommandFactory()
	{
	}
}
