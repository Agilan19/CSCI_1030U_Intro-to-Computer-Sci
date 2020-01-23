// Lab001.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: January 27, 2015
// Lab 02 – Basic Programming Lab

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Part 1 - Celsius to Fahrenheit Conversion

	//Get user to input Celsius value
	double celsius;
	cout << "Temperature in Celsius: ";
	cin >> celsius;

	//Use inputted Celsius value to calculate for Fahrenheit
	double fahrenheit = ((celsius * 9) / 5) + 32;
	cout << "Your inputted temperature in Fahrenheit is: ";
	cout << fahrenheit << endl;

	// Part 2 – Interest Calculator

	//Get user to input Principal Amount
	double principalAmount;
	cout << "Principal Amount (the amount someone has in the bank): ";
	cin >> principalAmount;

	//Get user to input Interest Rate
	double interestRate;
	cout << "Interest Rate (the annual rate by which the principle will increase: ";
	cin >> interestRate;

	//Calculate for the principal amount after 5 years
	double finalBankamount;
	finalBankamount = principalAmount * pow((1 + interestRate),5);
	cout << "Principal Amount after 5 years: ";
	cout << finalBankamount << endl;

	system("pause");

	return 0;

	/*
	Output:

	Temperature in Celsius: ______
	Your inputted temperature in Fahrenheit is: _____
	Principal Amount <the amount someone has in the bank>: _______
	Interest Rate <the annual rate by which the principle will increase: _____
	Principal Amount after 5 years: ______
	*/
}

