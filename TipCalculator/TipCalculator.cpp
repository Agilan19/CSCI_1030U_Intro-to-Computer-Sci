// TipCalculator.cpp : Defines the entry point for the console application.
//
// Author:       Agilan Ampigaiparhar
// Date:         January 27, 2015
// Description:  Tip Calculator

#include "stdafx.h"

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// YOUR CODE WILL GO HERE
	double subtotal; 
	double total;
	double tax = 1.13;
	double tip = 1.15;
	double tiptotal;

	cout << "Hello, please enter a subtotal: " << endl;
	cin >> subtotal;

	total = subtotal * tax;
	tiptotal = total * tip;

	cout << "Your total for the subtotal of: $" << subtotal << " is: $" << total << endl;
	cout << "Your total after tip, would be: $" << tiptotal << endl;

	system("pause");
 
	return 0;
}


