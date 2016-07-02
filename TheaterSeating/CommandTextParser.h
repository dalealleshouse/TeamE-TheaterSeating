#pragma once
#include "stdafx.h"

namespace theater
{
	using std::string;
	using std::vector;

	struct CommandText
	{
		string command;
		vector<string> arguments;
	};

	class CommandTextParser
	{
	public:
		CommandTextParser()
		{
		}

		CommandText Parse(string command);

		~CommandTextParser()
		{
		};
	};
}
