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

// declaration of HotDogStandClass
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
		void	display();
};

// HotDogStandClass constructor
HotDogStandClass::HotDogStandClass(int id, string location, double cost, int inventory, int numSold, int * totalSold)
{
	standID = id;
	standLocation = location;
	hotDogCost = cost;
	hotDogInventory = inventory;
	hotDogsSold = numSold;
	totalSoldPtr = totalSold;
}

// hotDogsBuy method, doesn't allow buy > inventory
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
		// tried to buy amount > inventory, print error message
		cout << "Current inventory is: " << hotDogInventory << endl;
		cout << "Buy amount requested was: " << amount << endl;
		cout << "Please retry buying less than " << hotDogInventory << endl;
	}
}

// stockInventory method, used to add more hot dog inventory
void HotDogStandClass::stockInventory(int amount)
{
	hotDogInventory += amount;
}

// display debug method, shows the current state of the object
void HotDogStandClass::display()
{
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "standID: " << standID << setw(29) << "standLocation: " << standLocation << endl;
	cout << "hotDogInventory: " << hotDogInventory << setw(20) << "hotDogsSold: " << hotDogsSold << endl;
	cout << "hotDogCost: " << hotDogCost << setw(21) << "totalSold: " << *totalSoldPtr << endl;
	cout << "-----------------------------------------------------------------------------" << endl << endl;
}

int totalSold = 0;

int main()
{
	// create three hotDogStand objects with initial values
	HotDogStandClass hotdogstand1(123, "69 Manhattan St. Rockledge, FL 32955", 2.15, 70, 0, &totalSold);
	HotDogStandClass hotdogstand2(456, "394 Jackson St. Muskego, WI 53150   ", 3.09, 30, 0, &totalSold);
	HotDogStandClass hotdogstand3(789, "888 Carson St. Burke, VA 22015      ", 1.95, 15, 0, &totalSold);

	// unit test all possible logic paths
	// test at least one path with each object
	cout << "initial stand 123" << endl;
	hotdogstand1.display();

	cout << "buy 30 in stock hot dogs from stand 123" << endl;
	hotdogstand1.hotDogsBuy(30);
	hotdogstand1.display();

	cout << "initial stand 456" << endl;
	hotdogstand2.display();

	cout << "try and buy 35 out of stock hot dogs from stand 456" << endl;
	hotdogstand2.hotDogsBuy(35);
	hotdogstand2.display();

	cout << "initial stand 789" << endl;
	hotdogstand3.display();

	cout << "restock 75 hot dogs to stand 789" << endl;
	hotdogstand3.stockInventory(75);
	hotdogstand3.display();

	cout << "buy 20 in stock hot dogs from stand 789 to show totalSold increase" << endl;
	hotdogstand3.hotDogsBuy(20);
	hotdogstand3.display();

	// pause the screen so that information can be read
	system("pause");	system("cls");
}