#include "stdafx.h"
#include "HelpCommand.h"
#include "CommandFactory.h"

namespace theater
{
	using std::stringstream;
	using std::setw;
	using std::endl;
	using std::left;

	string HelpCommand::Execute(vector<string> command_arguments)
	{
		auto fac{CommandFactory{_theater_services, _end_program}};

		stringstream ss{};

		for (const auto& cmd:fac.Commands())
				ss 
				<< setw(5)
				<< ""
				<< left
				<< setw(15) 
				<< cmd.first + ":"
				<< cmd.second->Description() << endl;

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
