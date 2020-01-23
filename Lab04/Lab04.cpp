// Lab04.cpp : Defines the entr(y point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: February 9, 2015
// Lab 04 - Iteration and Numerical Methods

#include "stdafx.h"
#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {

	//Define epsilon and define the number that will be inputted for square rooting.
	double epsilon = 0.000000001;
	double num = 0;

	//Get user to input the number to be squar rooted.
	cout << "Input a number: ";
	cin >> num;

	//Calculate the square root
	//Use the while loop to loop the calculation to find the closest approximtion of the square root of the inputted number.  
	double guess = num / 2.0;

	while (((abs((guess*guess) - num)) >= epsilon)){

			guess = guess - (((guess*guess) - num) / (2 * guess));
		}

	//Output the square root.
	cout << guess << endl;

	//It doesn't take significant extra time to gain extra precision due to the fast processing of Visual Studio. 

	//Part 2 - Approximation of Pi

	//Define the number of sides to be 3 as wanted in the assignment.
	double numberofsides = 3;

	//Define my output variable.
	double myPI = 0;

	//The equation uses 180 degrees, and to be converted into radians, I multiplied it by 0.0174533
	double radians = 180 * 0.0174533;

	//Use thr while loop to loop the calculation to approximate the value of Pi.
	while ((abs(PI - myPI)) >= epsilon){
	
		//Use the formula mentioned in the lab to produce the estimated Pi value.
		myPI = numberofsides * sin(radians / numberofsides);

		/* Use the number of sides as a counter to increase each time 
		producing more sides giving a closer approximation to Pi as shown 
		through Archimedes' method in which shapes with more sides produce 
		more closer approximations than those with less sides as it gets 
		closer to the circumference of a circle. */ 
		numberofsides++;
	}

	//Print out the number of sides of the polygon and the approximate value of Pi that was calculated.
	cout << "The estimated Pi value is: ";
	cout << myPI << endl;
	cout << "The polygon has: " << numberofsides << " sides" << endl;

	//End program.
	system("pause");
	return 0;

	/*
	Output:

	Input a number: ______
	2
	The estimated Pi value is: 3.14159
	The polygon has: 1920 sides
	*/
}

