// Lab03.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: February 3, 2015
// Lab 03 – Programming Basics II, Conditionals 

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Part 1 - Introductory Content

	//Printing the Part 1 message mentioned in the Lab 2 document 
	cout << "testing 1 2 3..." << endl;

	//Declaring the variables presented in the Lab 2 document and I added an end line addition for better formatting. 
	int Y = 8;
	cout << Y << endl;
	cout << Y * 2 << endl;

	//Declaring the variables for the other part presented in the Lab 2 document
	string name = "Carla Rodriguez Mendoza";
	float length = 14.5;
	float width = 7.25;

	//Printing the length and width as instructed in the Lab 2 document (except with spaces and new lines for better formatting after testing them out)
	cout << "length: " << length << endl;

	cout << "width: " << width << endl;

	//Presenting the basic sample if statement conditional example
	int X = 8;
	if (X < 10) {
		cout << "X is small" << endl;
	}
	else if (X < 20) {
		cout << "X is medium" << endl;
	}
	else {
		cout << "X is large" << endl;
	}

	//Part 2 - Mark to Letter Grade Conversion 

	//Declare grade/mark integer variable
	int mark;

	//Ask user to input the integer mark and receive the value
	cout << "Input a mark to be converted to a letter grade: ";
	cin >> mark;

	//The conditional if statements 

	//Use the chart given on the document to make if statements regarding all the possibilities of marks possible and print their corresponding Letter Grade marks. 
	
	//If mark is less than 50 and not equalling 50, print F
	if (mark < 50) {
		cout << "The Letter Grade is: F" << endl;
	}

	//If mark is 50 or over and below 60, print D
	else if (50 <= mark && mark < 60) {
		cout << "The Letter Grade is: D" << endl;
	}

	//If mark is 60 or over and below 70, print C
	else if (60 <= mark && mark < 70) {
		cout << "The Letter Grade is: C" << endl;
	}

	//If mark is 70 or over and below 80, print B
	else if (70 <= mark && mark < 80) {
		cout << "The Letter Grade is: B" << endl;
	}

	//If mark is 80 or over and below 100, print A
	else if (80 <= mark && mark < 100) {
		cout << "The Letter Grade is: A" << endl;
	}
	
	system("pause");

	return 0;

	/*
	Output: 

	testing 1 2 3...
	0
	16
	length: 14.5
	width: 7.25
	X is small
	Input a mark to be converted to a letter grade: _____
	The Letter Grade is: _____
	*/
}

