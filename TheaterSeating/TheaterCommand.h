#pragma once
#include "stdafx.h"
#include "TheaterServices.h"

namespace theater
{
	using std::string;
	using std::vector;
	class TheaterSeating;

	class TheaterCommand
	{
	protected:
		TheaterServices& _theater_services;
		bool& _end_program;
	public:
		TheaterCommand(TheaterServices& theater_services, bool& end_program)
			: _theater_services{theater_services}, _end_program{end_program}
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
