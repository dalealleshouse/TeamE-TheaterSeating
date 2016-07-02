#pragma once
#include "stdafx.h"
#include "CommandTextParser.h"
#include "CommandFactory.h"
#include "TheaterSeating.h"

namespace theater
{
	struct TheaterConfiguration;
	using std::string;
	using std::unique_ptr;
	class TheaterSeating;

	class CommandRunner
	{
		TheaterSeating _theater_seating;
		bool& _end_program;
		CommandFactory _command_factory;
		CommandTextParser _text_parser{CommandTextParser{}};
	public:
		CommandRunner(const TheaterConfiguration configuration, bool& end_program);
		string Run(string input);
		~CommandRunner();
	};
}
