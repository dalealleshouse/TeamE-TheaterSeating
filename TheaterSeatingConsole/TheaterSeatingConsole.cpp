#include "stdafx.h"
#include "../TheaterSeating/TheaterConfiguration.h"
#include "../TheaterSeating/CommandRunner.h"

using namespace theater;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::invalid_argument;

const unsigned int kNumberOfRows{10};
const unsigned int kSeatsPerRow{9};

void ShowError()
{
	cout << "I'm sorry, I don’t understand that statement. Please try again." << endl;
}

double GetPricePerSeat()
{
	string input{};

	while (true)
	{
		getline(cin, input);

		try
		{
			return stoi(input);
		}
		catch (invalid_argument&)
		{
			ShowError();
		}
	}
}

int main()
{
	cout << "Welcome to the ACME theater seating program!" << endl;
	cout << "Please enter the price per seat " << endl;

	auto price{GetPricePerSeat()};

	cout << "Enter a command to get started. Type help to get a list of available commands." << endl;

	string input{};
	auto end_program{false};
	auto runner(CommandRunner{TheaterConfiguration{price, kSeatsPerRow, kNumberOfRows}, end_program});

	while (!end_program)
	{
		getline(cin, input);
		cout << runner.Run(input) << endl;
	}

	return 0;
}
