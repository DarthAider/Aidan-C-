//********************************************************************************
// File Name:
// Author:
// Date:
// Class:
// Assignment:
// Purpose:
//********************************************************************************
#include <iostream>

using namespace std;

int main ()
{ 
	int minutes;
	double price;
	char time, cost;
	const double time1 = .10;
	const double time2 = .50;
	const double time3 = .25;
	
	cout << "***********************" << endl << "* Long-Distance Calls *" << endl 
		 << "***********************" << endl << endl;
	
	// Enter the starting time of the call
	cout << "Enter Starting Time Of Call: ";
	cin >> time;

	// Enter Call Duration in minutes
	cout << endl << "Enter Call Duration <in minutes>: ";
	cin >> minutes;

	if (00:00 <= time <= 06:59)
	{
	cost = time1;
	}

	if (7:00 <= time <= 18:59)
	{
	cost = time2;
	}

	if (19:00 <= time <= 23.59)
	{
	cost = time3;
	}

	// Calculate the price of the call
	price = cost * minutes

	// Display the price of the call
	cout << "Price Of Call: ";
	cin >> price

	return EXIT_SUCCESS;

}