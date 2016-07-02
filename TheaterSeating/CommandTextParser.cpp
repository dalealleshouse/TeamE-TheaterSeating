#include "stdafx.h"
#include "CommandTextParser.h"

namespace theater
{
	using std::istringstream;

	string Trim(string& str)
	{
		auto first = str.find_first_not_of(' ');
		auto last = str.find_last_not_of(' ');
		return str.substr(first, (last - first + 1));
	}

	CommandText CommandTextParser::Parse(string command)
	{
		auto result = CommandText{"", vector<string>{}};
		istringstream ss{command};
		ss >> result.command;

		string argument{};
		while (getline(ss, argument, ','))
		{
			result.arguments.push_back(Trim(argument));
		}

		return result;
	}
}
