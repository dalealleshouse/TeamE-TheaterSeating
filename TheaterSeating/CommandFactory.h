#pragma once
#include "stdafx.h"
#include "TheaterCommand.h"

namespace theater
{
	using std::shared_ptr;
	using std::map;

	class CommandFactory
	{
		TheaterServices& _theater_services;
		bool& _end_program;
		shared_ptr<TheaterCommand> _not_found_command;

		map<string, shared_ptr<TheaterCommand>> _commands;
		void CommandFactory::PushCommand(shared_ptr<TheaterCommand>& cmd);
	public:
		CommandFactory(TheaterServices& theater_seating, bool& end_program);
		shared_ptr<TheaterCommand> Build(string command);
		const map<string, shared_ptr<TheaterCommand>>& Commands();
		~CommandFactory();
	};
}
