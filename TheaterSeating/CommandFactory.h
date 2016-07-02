#pragma once
#include "stdafx.h"
#include "TheaterCommand.h"

namespace theater
{
	using std::shared_ptr;

	class CommandFactory
	{
		TheaterServices& _theater_services;
		bool& _end_program;
		shared_ptr<TheaterCommand> _not_found_command;

		vector<shared_ptr<TheaterCommand>> _commands;
	public:
		CommandFactory(TheaterServices& theater_seating, bool& end_program);
		shared_ptr<TheaterCommand> Build(string command);
		const vector<shared_ptr<TheaterCommand>>& Commands();
		~CommandFactory();
	};
}
