// Lab05.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: February 24, 2015
// Lab 05 - Functions I

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

/*
Pi is a double variable and so the function needs to be a double. The argument is taking in the number of sides to enter the function in which the number of sides have to be of an integer value. 
*/
double estimatePi(int numofSides) {

	//Define epsilon
	double epsilon = 0.000000001;

	//Define my output variable.
	double myPI = 0;

	//The equation uses 180 degrees, and to be converted into radians, I multiplied it by 0.0174533
	double radians = 180 * 0.0174533;

		//Use the formula mentioned in the lab to produce the estimated Pi value.
		myPI = numofSides * sin(radians / numofSides);

    //Return to equal the function call in the main function. 
	return myPI;
}

/*
Declare function for Part 2 with three arguments that effect the function being the upper bound, lower bound, and original vector. 
*/
vector<int> getMembersInRange(vector<int> originalVector, int upperBound, int lowerBound) {
	 
	//Declare the modified vector. 
	vector<int> modifiedVector;

	//Make a for loop in which it runs through each integer of the original vector based on the size of the vector. 
	for (int i = 0; i < originalVector.size(); i++) {

		//Use an if statement to push back only integers within the vector that are greater or equal to the upper bound and less than or equal to the lower bound. 
		if (originalVector[i] >= upperBound && originalVector[i] <= lowerBound) {
			modifiedVector.push_back(originalVector[i]);
		}
	}

	//Use a for loop to print each vector that passed the parameters of the if statement individually per loop. It loops based on the size of integers that passed through the parameters successfully and loops to that amount of times to print all the modified vector's integers. 
	for (int i = 0; i < modifiedVector.size(); i++) {
		cout << modifiedVector[i] << endl;
	}

	//Return the original vector back to main as the neccessary modified vector has already been printed and the original vector must not change. 
	return originalVector;

}

/*
Declare Part 3 function with the argument being the vector of integers from the main function. It uses pass by reference knowing the vector will change using modulus to distinguish the even integers. 
*/
void removeEven(vector<int> &noEvenVector){

	//Use a for loop to read through each integer corresponding to the size of the integer vector. 
	for (int j = 0; j < noEvenVector.size(); j++) {

		//Modulus uses remainder after division and so is useful in distinguishing between odd and even integers. The if statement uses this parameter test knowing the even integers will pass this parameter only to be erased to remove the even integers. 
		if (noEvenVector[j] % 2 == 0) {

			noEvenVector.erase(noEvenVector.begin() + j);

		}

	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	Part 1 - Pi Estimation
	*/
	//Declare answer1 to equal the function call of Part 1 with number of sides to be equal to what the argument is chosen to bw. 
	double answer1 = estimatePi(9920);
	//Use the built in precision function to print more decimal places for greater accuracy and to show that with the greater number of sides, Pi becomes more accurate. 
	cout.precision(17);
	cout << answer1 << endl;

	/*
	Part 2 - Upper and Lower Bound Organization
	*/
	//Declare upper bound and lower bound and fill the original vector with integers. 
	int upperBound = 7;
	int lowerBound = 19;
	vector<int> originalVector = { 4, 14, 12, 16, 27, 38, 49, 2, 19 };

	//Every integer that fits within upper and lower bounds will be printed one per line in order of appearance (left to right) in the vector. 
	cout << endl;
	//Make a function call inputting the declared original vector, upper bound, and lower bound into the Part 2 function.
	getMembersInRange(originalVector, upperBound, lowerBound);

	/*
	Part 3 - Removing Even Numbers
	*/
	//Declare a vector full of random integers that will later be modified to remove even integers. This vector is a vector with even integers then later becomes a vector with no even integers. 
	vector<int> evenVector = { 4, 2, 1, 11, 45, 18, 19, 21, 22, 27, 38 };

	//Make a function call to input the vector mentioned above into the removeEven Part 3 function in order to eliminate the even integers. 
	removeEven(evenVector);

	//Prints the odd integers, one per line in order of appearance (left to right) in the vector.
	cout << endl;

	//Use the for loop to print the odd integers within the vector one integer at a time corresponding to the new size of vector (amount of odd integers in the vector). 
	for (int k = 0; k < evenVector.size(); k++) {
		cout << evenVector[k] << endl;
	}

	system("pause");

	/*
	Output:

	3.1415939474859425

	14
	12
	16
	19

	2
	1
	11
	45
	19
	21
	27
	*/
}

