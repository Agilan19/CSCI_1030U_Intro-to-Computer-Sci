// Lab08.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: March 23, 2015
// Lab 08 - Algorithms
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Part 1 - Least to Greatest Sort Algorithm

/*
The instructions says to return noting, and so its a void function with the vector of
integers to be sorted as the argument. 
*/
void insertionSort(vector <int> &toBeSorted) {

	//This code is based on the pseudocode from the PowerPoint changed to match C++ logic. 
	/*
	Make a for loop where the counter is to reach size -1 as i starts at 0. 
	*/
	for (int i = 0; i < toBeSorted.size() - 1; i++){
		
		//Set another counter j to equal i.
		int j = i;

		/*
		Make a while loop in which the code runs as long as the counter j is over 0 and
		the index of the vector of integers is set to j - 1 and that has to be greater 
		than the index of the vector to continue running. 
		*/
		while (j > 0 && toBeSorted[j - 1]>toBeSorted[j]){

			/*
			Set the integer temp to equal to the integer value of the index j of the
			vector of integers. 
			*/
			int temp = toBeSorted[j];

			/*
			The vector of integers of index j is set equal to the preceding index. 
			*/
			toBeSorted[j] = toBeSorted[j - 1];

			/*
			The preceding index is then set to integer temp. 
			*/
			toBeSorted[j - 1] = temp;

			/*
			The counter j is set to decrease minus 1 each time the while loop loops.
			*/
			j--;
		}
	}
}

//Part 2 - Binary Search Algorithm

/*
To return a boolean value, the function will be a boolean function. It will take four 
arguments as mentioned in the lab assgnment doc. 
*/
bool binarySearchRec(int find, vector <int> vect, int start, int end){

	/*
	Make an if statement in which the code will return false as long as value start is 
	greater than end.
	*/
	if (start > end) {
		return false;
	}

		/*
		Make an integer variable that will take the value for middle which be the index
		for the vector as it checks for the integer starting from the middle while 
		recursively going from both the left and right of the middle to check the entire 
		vector.
		*/
		int middle = ((end - start) / 2) + start;

		/*
		Make an if statement to check if the value to look for matches the middle element
		in which the purpose of the program is successful and it already found the match 
		and so it is able to return true.
		*/
		if (find == vect[middle]) {
			return true;
		}

		/*
		Make an else if statement that will check if the integer find value is less than 
		the middle element of the vector in which case, the code will return recursively
		replacing end with middle - 1 and then back to start of the function checking from
		the left. 
		*/
		else if (find < vect[middle]) {
			return binarySearchRec(find, vect, start, middle - 1);
		} 

		/*
		Return middle + 1 to replace end in any other situation, specifically if find is 
		less than the the middle element of the vector to check the elements to the right.
		*/
		else {
			return binarySearchRec(find, vect, middle + 1, end);
		}
}

/*
Make another boolean function taking in the same arguments except this time using iterations.
*/
bool binarySearchIter(int find, vector <int> vect, int start, int end) {

	/*
	The code will run as long as end is larger than start.
	*/
	while (start < end) {

		/*
		Declare the middle variable again to be used as a starting spot to check
		within the vector from the middle. 
		*/
		int middle = ((end - start) / 2) + start;

		/*
		Use the same conditionals as the recursive version.
		*/
		if (vect[middle] == find) {
			return true;
		}

		else if (find < vect[middle]) {
			end = middle - 1;
		}

		else {
			start = middle + 1;
		}
	}
	/*
	Return false when the while loop is complete, and the code has checked both to the left
	and to the right from the middle element and when the find value does not match any of
	the elements and the whole vector has been checked, return false.
	*/
	return false;
}

/*
Main function
*/
int _tmain(int argc, _TCHAR* argv[]) {

	/*
	Declare the vector of integers that will be sorted.
	*/
	vector <int> VectortoBeSorted = { 1, 0, 12, 15, 91, 71, 74, 42, 58, 59, 61, 21, 27, 29 };

	/*
	Make a function call with the vector of integers being inputted as an argument of the
	function.
	*/
	insertionSort(VectortoBeSorted);

	/*
	Make a for loop to return the results for Part 1 by going through the modified vector
	of integes with pass by reference in which the function sorted the integers from least 
	to greatest and now this for loop will loop through each element and print each 
	element per line in order.
	*/
	for (int i = 0; i < VectortoBeSorted.size() - 1; i++) {
		cout << VectortoBeSorted[i] << endl;
	}

	/*
	Print the returned boolean results for Part 2 by making a function call and inputting
	start, end, find values and the vector of integers.
	*/
	cout << endl << binarySearchRec(11, VectortoBeSorted, 0, 14) << endl;

	cout << endl << binarySearchIter(1, VectortoBeSorted, 0, 14) << endl << endl;


	system("pause");
	return 0;

	/*
	Output:
	0
	1
	12
	13
	15
	21
	27
	42
	58
	59
	61
	71
	74
	91

	0

	1
	*/

}