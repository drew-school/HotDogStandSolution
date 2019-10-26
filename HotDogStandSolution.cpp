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

int totalSold = 0;

int main()
{
	// formats all numbers >999 to include separating commas
	cout.imbue(locale(""));

	HotDogStandClass h(1,"test",2.15,10,0,&totalSold);
	cout << totalSold << endl;
	h.hotDogsBuy(5);
	cout << totalSold << endl;
	h.hotDogsBuy(10);
	cout << totalSold << endl;
	h.stockInventory(5);
	h.hotDogsBuy(10);
	cout << totalSold << endl;
}