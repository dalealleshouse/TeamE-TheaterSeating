#pragma once
#include "stdafx.h"
#include "CommandTextParser.h"
#include "CommandFactory.h"

namespace theater
{
	struct TheaterConfiguration;
	using std::string;
	using std::unique_ptr;
	class TheaterSeating;

	class CommandRunner
	{
		TheaterServices _theater_services;
		bool& _end_program;
		CommandFactory _command_factory;
		CommandTextParser _text_parser{CommandTextParser{}};
	public:
		CommandRunner(const TheaterConfiguration configuration, bool& end_program, ConfirmFunc confirm);
		string Run(string input);
		~CommandRunner();
	};
}
