#include "stdafx.h"
#include "CommandRunner.h"
#include "TheaterConfiguration.h"
#include "TheaterSeating.h"

namespace theater
{
	using std::make_unique;

	CommandRunner::CommandRunner(const TheaterConfiguration configuration, bool& end_program)
		: _theater_seating{TheaterSeating{configuration}}, _end_program{end_program}
		  , _command_factory{CommandFactory{_theater_seating, end_program}}
	{
	}

	string CommandRunner::Run(string input)
	{
		auto ct = _text_parser.Parse(input);
		auto cmd = _command_factory.Build(ct.command);
		return cmd->Execute(ct.arguments);
	}

	CommandRunner::~CommandRunner()
	{
	}
}
