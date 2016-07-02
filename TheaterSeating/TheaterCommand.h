#pragma once
#include "stdafx.h"

namespace theater
{
	using std::string;
	using std::vector;
	class TheaterSeating;

	class TheaterCommand
	{
	protected:
		TheaterSeating& _theater_seating;
		bool& _end_program;
	public:
		TheaterCommand(TheaterSeating& theater_seating, bool& end_program)
			: _theater_seating{theater_seating}, _end_program{end_program}
		{
		};

		string Execute()
		{
			return Execute(vector<string>{});
		}

		virtual string Execute(vector<string> command_arguments) = 0;

		virtual string Name() =0;

		virtual string Description() =0;

		virtual bool IncludeInHelp()
		{
			return true;
		};

		virtual ~TheaterCommand()
		{
		}
	};
}
