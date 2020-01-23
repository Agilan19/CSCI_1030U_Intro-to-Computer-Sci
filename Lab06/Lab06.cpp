// Lab06.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: March 16, 2015
// Lab 06 - Functions II
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//Initialize global variable for Part 2's Recursion
int x = 0;

//Part 1 - A: Iterations
double constantInvestmentI (double principal, double annualContrib, double growthRate, int years) {

	//Make a new local variable to make for principal for simplicity. 
	double finalBankAmount = principal;

	//Make a for loop where the counter i is set equal to years - 1. The finalBankAmount will change 5 times equal to the years. 
	for (int i = years-1; i >= 0; i--) {

		//Concatenate finalBankAmount to equal annualContrib + finalBankAmount.
		finalBankAmount += annualContrib;
		//Using the new finalBankAmount value, make that equal to that value times the growth rate added to the new final bank amount.
		finalBankAmount += finalBankAmount*growthRate;

	}

	return finalBankAmount;

}

//Part 1 - B: Recursion
double constantInvestmentR(double principal, double annualContrib, double growthRate, int years) {

	//Make a new local variable to make for principal for simplicity. 
	double finalBankAmount = principal;

	//Concatenate finalBankAmount to equal annualContrib + finalBankAmount.
	finalBankAmount += annualContrib;
	//Using the new finalBankAmount value, make that equal to that value times the growth rate added to the new final bank amount.
	finalBankAmount += finalBankAmount*growthRate;

	//Use Recursion where the program runs as long as the changing years is set to equal 0 but it needs to be years-1 because c++ starts with 0 in position.
	if (years - 1 > 0) {
		//Return the function with years decreasing by 1 each time until years - 1 is equal to 0.
		return constantInvestmentR(finalBankAmount, annualContrib, growthRate, years - 1);
	}

	//Once the program follows the paramater mentioned above, it will return the latest finalBankAmount value. 
	else {
		return finalBankAmount;
	}
}

//Part 2 - A: Iterations
double variableInvestmentI (double principal, double annualContrib, vector <double> growthRates, int years) {

	//Make a new local variable to make for principal for simplicity. 
	double finalBankAmount = principal;

	//Use a for loop similar to Part 1. The counter i is set equal to 0. The i will change to the integer value one less than years. 
	for (int i = 0; i < years; i++) {
		finalBankAmount += annualContrib;
		finalBankAmount += finalBankAmount*growthRates[i];

	}

	return finalBankAmount;

}

//Part 2 - B: Recursion
double variableInvestmentR(double principal, double annualContrib, vector <double> growthRates, int years) {
	
	//Make a new local variable to make for principal for simplicity. 
	double finalBankAmount = principal;

	//Use an if statement to run as long as years is not equal to 0.
	if (years != 0) {

	//Use the same concantenation technique for addition used in the other Parts again except this time using the global variable x to go through the different vector of growth rates. 
	finalBankAmount += annualContrib;
	finalBankAmount += finalBankAmount*growthRates[x];

		//Global variable increases by one each time it loops untilyears is equal to 0.
		x++;
		return variableInvestmentR(finalBankAmount, annualContrib, growthRates, years-1);
	}

	else {
		//Returns the latest finalBankAmount value when the years is equal to 0.
		return finalBankAmount;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{

	//Calling the functions back into main and returning the result from the functions.

	//Part 1: A
	double result = constantInvestmentI(0, 10000, 0.05, 5);
	cout.precision(15);
	cout << result << endl;

	//Part 1: B
	double result1 = constantInvestmentR(0, 10000, 0.05, 5);
	cout.precision(15);
	cout << result1 << endl;

	//Make vector of growth rates.
	vector <double> growthRates = { 0.05, 0.03, 0.015, 0.045, 0.06 }; 

	//Part 2: A
	double result2 = variableInvestmentI(0, 10000, growthRates, 5);
	cout.precision(15);
	cout << result2 << endl;

	//Part 2: B
	double result3 = variableInvestmentR(0, 10000, growthRates, 5);
	cout.precision(15);
	cout << result3 << endl;

	system("pause");

	return 0;

	/*
	Output:

	58019.128125
	58019.128125
	56660.0767825
	56660.0767825
	*/
}

