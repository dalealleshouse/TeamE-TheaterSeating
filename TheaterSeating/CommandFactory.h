#pragma once
#include "stdafx.h"
#include "TheaterCommand.h"

namespace theater
{
	using std::shared_ptr;

	class CommandFactory
	{
		TheaterSeating& _theater_seating;
		bool& _end_program;
		shared_ptr<TheaterCommand> _not_found_command;

		vector<shared_ptr<TheaterCommand>> _commands;
	public:
		CommandFactory(TheaterSeating& theater_seating, bool& end_program);
		shared_ptr<TheaterCommand> Build(string command);
		const vector<shared_ptr<TheaterCommand>>& Commands();
		~CommandFactory();
	};
}
