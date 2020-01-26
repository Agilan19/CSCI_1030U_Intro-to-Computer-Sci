// Ampigaipathar_Agilan_100553054_Assignment_1.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: February 23, 2015
// Assignment 1 - Various Functions

/*
Declare the preproccessors that will be used within this program.
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

//Part 1 - Simulate Projectile

/*
Declare the function for Part 1 with the two arguments of the initial vertical 
velocity (initialVelocity) and the duration of each time step (deltaT).
*/
double simulateProjectile(double initialVelocity, double deltaT) {

	/*
	Declare the variables that will be used in Part 1
	and give them basic values like 0 for initialization. Double was used for more 
	specific inputs to be given as well as to better handle formulas involving gravity (g).

	Declare g to equal -9.8 m/s^2.
	*/

	double finalVelocity;
	double g = -9.8;
	double peakHeight;
	double peakTime = 0;
	double impactTime = 0;

	/*
	Declare the final velocity to equal the initial velocity
	subtracted by g multiplied by delta time just as the formula states.
	*/
	finalVelocity = initialVelocity - (g*deltaT);

	/*
	Time value in which peak (maximum) height is reached.

	Projectile motion happens in a parabolic arc, and so in the
	center between both impact times (x-intercepts) is where the maximum
	height is located.

	Using the formula for mazimum height time, this function will pull the 
	initial velocity from the main function and use it here to get the pmaximum height
	time value. 
	*/
	peakTime = ((initialVelocity) / (-g));

	/*
	The impact time is known to be the time in which maximum height is achieved times two.
	This makes sense considering the maximum height is a negative parabolic arc in which
	the maximum height happens in the middle between both impact times (x-intercepts) 
	and assuming the projectile is launched from the ground, that would be a time of 0s 
	and the impact time in which the projectile comes back down is then simply two times
	the peak time because the peak time comes in halfway between the time launched from
	the ground and the impact time when the projectile comes back to the ground. 
	*/
	impactTime = (peakTime * 2);

	/*
	The maximum height is simply substituting in the peakTime
	(the time in which maximum height is achieved) into the
	kinematic height equation and the result will be the maximum
	height.
	*/
	peakHeight = ((initialVelocity*peakTime) - (0.5*g*(peakTime*peakTime)));

	/*
	Printing out maximum height for the inputted initial velocity through the main
	function as instructed. 
	*/
	cout << "The peak height is: " << peakHeight << " m." << endl;

	/*
	The function will now return the impact time value as instructed. The main function
	will be able to call on this function and input two double values to be used as the
	two arguments in this function, initial velocity and deltaT. The result would be this
	returned value for impact time. 
	*/
	return impactTime;

}

//Part 2 - Reverse Complement Nucleotide Sequence

/*
Declare the function for Part 2 with the instructed argument to take a vector
of nucleotides called sequence and another argument for size of the vector which is
important in reading every nucleotide using a loop. In order to use a vector argument and
an integer argument, a void function was used. I chose a char vector because the
nucleotides are all one letter which makes it a character. I used Pass by Reference because I know
the argument variable, sequence will change when getting converted into complement nucleotides and
so due to the pass values' modifications, pass by reference is neccessary for the strategy I'm 
using. 
*/
void reverseComplement(vector <char> &sequence, int size) {

	/*
	Use a for loop to read through every nucleotide of the vector. This works as the
	counter i is set to zero, and to read through every nucleotide, it needs to run as 
	many times as one integer less than greater to the size of the vector which is 
	equal to the number of nucleotides within the vector. This way, even if 
	the vector's quantity was to change, the program would just adjust and still work. 
	*/
	for (int i = 0; i < size; i++) {

		/*
		Use a series of if and else if statements to detect when a nucleotide appears through
		the vector using the for loop and changing the char value of each nucleotide to its
		corresponding complement nucleotide based on which nucleotide appears using the parameters
		set by the if statements. With this, the sequence of nucleotides have all been converted 
		into the sequence of complement nucleotides. 
		*/
		if (sequence[i] == 'G') {
			sequence[i] = 'C';
		}

		else if (sequence[i] == 'C') {
			sequence[i] = 'G';
		}

		else if (sequence[i] == 'A') {
			sequence[i] = 'T';
		}

		else if (sequence[i] == 'T') {
			sequence[i] = 'A';
		}
	}

	cout << endl;

	/*
	Use a reverse for loop in which its paramaters are the opposite to that of the above for loop
	in order to reverse the sequence. The counter j is set equal the size of the vector as done in
	the main function. The for loop will loop until j is no longer greater than zero while j
	decreases by one for every loop as the modified sequence (complement sequence) prints backwards
	one by one for each nucleotide resulting in the reverse complement sequence. 
	*/
	for (int j = size - 1; j >= 0; j--) {
		cout << sequence[j] << " ";
	}

}

//Part 3 - Gregory-Liebniz Series Pi Estimation

/*
Declare the function for Part 3. Pi is a decimal value and so the return would have to be a 
double value and for that to happen, the function type has to be a decimal. The only argument 
needed is the number of iterations as this function is meant to loop the iterations as to increase
one each time to reach the closest approximation of Pi. 
*/
double gregoryLiebniz(int numIterations) {

	/*
	Declare and initiate the local variables to be used in this function. 
	*/
	double PiFormula = 0;
	double estimatePi = 0;

	/*
	Use a for loop to loop the counter as long as the number of iterations are greater than the counter
	in which the counter would eventually reach to equal the number of iterations set in the function
	call in the main function. 
	*/
	for (int i = 0; i < numIterations; i++) {

		/*
		Set the pi formula to equal the formula mentioned in the assignment document except this time 
		replacing the number of iterations with the counter which eventually results in the number of 
		iterations while doing this formula calculation resuling in an accurate Pi approximation for
		the greater the function call argument value was set.
		*/
		PiFormula = ((4 * pow(-1, i)) / ((2 * i) + 1));

		/*
		In order to prevent any looping calculation errors, I set another variable to equal the 
		pi approximate in which it would equal the PiFormla value because the initiation was set to
		zero and zero plus the calculated pi formula value results in the same pi formula value. This
		was done more as a measure of safety. 
		*/
		estimatePi += PiFormula;
	}

	/*
	Makes a line gap between Part 3 and 4.
	*/
	cout << endl;

	/*
	Return the estimatePi value which is equal to the PiFormula value back to the main as the result
	after the argument went through the function. 
	*/
	return estimatePi;

}

//Part 4 - Intersection of Two Integer Vector Sets

/*
Declare a vector integer function considering both arguments will be two integer vector sets.
*/
vector <int> intersect(vector<int> s1, vector<int> s2) {

	/*
	Declare the vector to be modified.
	*/
	vector <int> commonElement;

	/*
	Use a nested for loop to check every single possibility for a common element between both integer
	vector sets (intersection). In order to do this, a nested for loop will run with the first integer
	of the first vector of integers checking with every integer of the second vector of integers to
	find a common element among them. Once, it runs through the first integer of the first vector of 
	integers, it will move on to the second integer and compare it to all the second vector of integers
	one by one again. This pattern will repeat up to the last integer of the first vector of integers 
	in which it will stop looking for common elements at that point once the last integer of the first 
	vector of integers has checked with the last integer of the second vector of integers. When a 
	common element is found, it will be pushed back into the common element vector. The nested for 
	loops are vector size dependent and so this pattern could work with any number of integers within
	the vectors as well as any positive integer.
	*/

	/*
	Make a for loop in which the loop will run through each integer of the first vector of integers
	corresponding to the size of the first vector. 
	*/
	for (int i = 0; i < s1.size(); i++) {

		/*
		Make another for loop, now creating a nested for loop in which this for loop is for running
		through all the integers of the second vector of integers also dependent on the size of the 
		vector. 
		*/
		for (int j = 0; j < s2.size(); j++) {

			/*
			Use an if statement to check if the elements match in both vectors among the looping 
			counters. This can even check, for example, the third integer of the first vector of 
			integers was to match with the sixteenth integer of the second vector of integers. 
			*/
			if (s1[i] == s2[j]) {

				/*
				The created vector to store common elements among both vector of integers will then
				store these common integers that were detected within the nested for loop and push them
				back in order of appearance into this vector. 
				*/
				commonElement.push_back(s1[i]);

			}
		}
	}

	/*
	This will now return the common element vector back to main function and present the common 
	elements among both vecor of integers. 
	*/
	return commonElement;
}

/*
Main Function
*/
int main() {

	//Part 1

	/*
	Declare the official impact time and make it equal to the function call with the two
	arguments having double values to be put back into the simulateProjectile function
	and return the impact time. 
	*/
	double OfficialimpactTime;
	OfficialimpactTime = simulateProjectile(12.7, 15.6);

	/*
	Use the built in precision function to give the final returned value of impact time 
	to be more accurate and be able to hold more decimal places and unrounded. 
	*/
	cout.precision(17);

	/*
	Print out the impact time of the projectile in seconds. 
	*/
	cout << "The impact time of the projectile is: " << OfficialimpactTime << " s." << endl;

	//Part 2

	/*
	Considering the individual nucleotides are made up of one letter, I chose to make the whole
	vector a char vector while filling the vector with the char nucleotides.
	*/
	vector<char> nucleotides = { 'G', 'C', 'A', 'T', 'C', 'A', 'G', 'T', 'A', 'T', 'G', 'C' };

	/*
	I made an integer value called size equalling the size of the vector, so if one wants to add
	more nucleotides, change, or decrease the number of nucleotides, the program will still work
	despite any change to the number of nucleotides in the vector. This makes it more convenient
	because by placing it in main, it becomes a global variable and so I can make reference to 
	the size of the vector by simply using this variable in the for loops in the function to loop 
	according to the size of the vector to run through each individual nucleotide.
	*/
	int size = nucleotides.size();

	/*
	I called the function for Part 2, with the vector of nucleotides going in as the vector sequence
	and the size of the vector as the other argument to use it as a global variable through the 
	function.
	*/
	reverseComplement(nucleotides, size);

	/*
	Make a gap between Part 2 and Part 3 for neatness. 
	*/
	cout << endl;

	//Part 3 

	/*
	Declare global variables for Part 3 as well as function call with the argument to calculated 
	through the function and printed back to main. The precision is to get more accurate results 
	with more decimal places with less rounding. 
	*/
	double PiOfficial;
	PiOfficial = gregoryLiebniz(30000);
	cout.precision(17);
	cout << PiOfficial << endl;

	//Part 4

	/*
	Make two different vectors of integers with some common elements.
	*/
	vector<int> Vector1 = { 4, 3, 2, 44, 48, 39, 72, 79, 91, 99, 11 };
	vector<int> Vector2 = { 2, 1, 17, 19, 21, 27, 78, 79, 81, 97, 12, 99, 72 };

	//Declare the global vector where the common elements will be stored. 
	vector<int> commonElements;

	cout << endl;

	/*
	Make a function call from Part 4 in which the common element vector will be filled with 
	the results of putting in the two made vectors of integers (Vector1 and Vector2) into the function
	to get these results (the common elements) that got stored into a vector of its own.
	*/
	commonElements = intersect(Vector1, Vector2);
	
	/*
	In order to access, and print the common elements that got placed into its own vector, the for 
	loop will run through each integer and print them one by one dependent on this vector's size 
	and so all the common elements will be printed with a space in between for ease in reading it
	and neatness. 
	*/
	for (int m = 0; m < commonElements.size(); m++) {

		cout << commonElements[m] << " ";

	}

	cout << endl;

	/*
	End program: press any key to continue. 
	*/
	system("pause");

	/*
	Outut:

	The peak height is: 24.6872 m.
	The impact time of the projectile is: 2.5918367346938771

	G C A T A C T G A T G C
	
	3.1415593202564418

	2 72 79 99
	*/

}