#include "stdafx.h"
#include "HelpCommand.h"
#include "CommandFactory.h"

namespace theater
{
	using std::stringstream;

	string HelpCommand::Execute(vector<string> command_arguments)
	{
		auto fac{CommandFactory{_theater_services, _end_program}};

		stringstream ss{};

		for (auto cmd:fac.Commands())
			if (cmd->IncludeInHelp())
				ss << "\t" << cmd->Name() << ": " << "\t" << cmd->Description() << "\n";

		return ss.str();
	}

	string HelpCommand::Name()
	{
		return "help";
	}

	string HelpCommand::Description()
	{
		return "Prints help text for all commands.";
	}
}
