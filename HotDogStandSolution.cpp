/*
Module Name:	Hot Dog Stand Class
Date:			11-6-2019
Author:			Drew Pulliam

Module Purpose
Track hotdog stand business using classes

Module Design Description

Inputs:
None

Outputs:
Unit test of all possible logic paths in the program

*/

#include "pch.h"

#include <safeint.h>
#include <chrono>
#include <limits>
#include <locale>

#include <iostream>
#include <iomanip>

#include <string>

using namespace std;
using namespace msl::utilities;
using namespace chrono;

class HotDogStandClass 
{
	private:
		int		standID;
		string	standLocation;
		double	hotDogCost;
		int		hotDogInventory;
		int		hotDogsSold;
		int*	totalSoldPtr;
	public:
		HotDogStandClass(int id, string location, double cost, int inventory, int numSold, int * totalSold);
		int		getStandID()		{ return standID; };
		string	getStandLocation()	{ return standLocation; };
		double	getHotDogCost()		{ return hotDogCost; };
		int		getHotDogInventory(){ return hotDogInventory; };
		int		getHotDogsSold()	{ return hotDogsSold; };
		void	hotDogsBuy(int amount);
		void	stockInventory(int amount);
		string	display();
};

HotDogStandClass::HotDogStandClass(int id, string location, double cost, int inventory, int numSold, int * totalSold)
{
	standID = id;
	standLocation = location;
	hotDogCost = cost;
	hotDogInventory = inventory;
	hotDogsSold = numSold;
	totalSoldPtr = totalSold;
}

void HotDogStandClass::hotDogsBuy(int amount)
{
	if (hotDogInventory - amount >= 0)
	{
		*totalSoldPtr += amount;
		hotDogInventory -= amount;
		hotDogsSold += amount;
	}
	else
	{
		cout << "Current inventory is: " << hotDogInventory << endl;
		cout << "Buy amount requested was: " << amount << endl;
		cout << "Please retry buying less than " << hotDogInventory << endl;
	}
}

void HotDogStandClass::stockInventory(int amount)
{
	hotDogInventory += amount;
}

string HotDogStandClass::display()
{
	return "--------------------------------------------------------------\nstandID: " + to_string(standID) + ", standLocation: " + standLocation + ", hotDogCost: " + to_string(hotDogCost) + "\nhotDogInventory: " + to_string(hotDogInventory) + ", hotDogsSold: " + to_string(hotDogsSold) + ", totalSold: " + to_string(*totalSoldPtr);
}

int totalSold = 0;

int main()
{
	// formats all numbers >999 to include separating commas
	cout.imbue(locale(""));

	HotDogStandClass hotdogstand1(123, "456 main st", 2.15, 70, 0, &totalSold);
	HotDogStandClass hotdogstand2(456, "456 main st", 3.00, 30, 0, &totalSold);
	HotDogStandClass hotdogstand3(789, "456 main st", 1.95, 15, 0, &totalSold);

	cout << "initial stand 123" << endl;
	cout << hotdogstand1.display() << endl << endl;

	cout << "buy in stock hot dogs from stand 123" << endl;
	hotdogstand1.hotDogsBuy(30);
	cout << hotdogstand1.display() << endl << endl;

	cout << "initial stand 456" << endl;
	cout << hotdogstand2.display() << endl << endl;

	cout << "try and buy out of stock hot dogs from stand 456" << endl;
	hotdogstand2.hotDogsBuy(35);
	cout << hotdogstand2.display() << endl << endl;

	cout << "initial stand 789" << endl;
	cout << hotdogstand3.display() << endl << endl;

	cout << "restock stand 789" << endl;
	hotdogstand3.stockInventory(85);
	cout << hotdogstand3.display() << endl << endl;

	cout << "buy in stock hot dogs from stand 789 to show totalSold" << endl;
	hotdogstand3.hotDogsBuy(20);
	cout << hotdogstand3.display() << endl << endl;
}