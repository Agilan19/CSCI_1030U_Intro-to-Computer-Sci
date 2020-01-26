// Ampigaipathar_Agilan_100553054_Assignment2.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: March 28, 2015
// Assignment 2 - Simulation and Algorithms

/*
Declare the preproccessors that will be used within this program.
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//Part 1 - Simulate Bungee Jumping

/*
Declare the class for Part 1.
*/
class FallingObject {

/*
These instance variables are instructed to have get functions (accessors) and so their corresponding get
functions need to be in the public section. 
*/
public:
	FallingObject(float mass1, float surfaceArea1, float bungeeSpringConstant1, float bungeeUnstretchedLength1);

	void simulateTimestep(float time);

	float getMass();
	float getSurfaceArea();
	float getBungeeSpringConstant();
	float getBungeeUnstretchedLength();
	float getGravity();
	float getDistance();
	float getVelocity();
	float getAcceleration();

/*
As instructed in the assignment, the mass, surface area, bungee spring constant, and bungee unstretched
length should be set values meaning they should be in the private section. The values are meant to be
concrete and unchangeable and so they need to be in the private section while to access them, their 
corresponding get functions are placed in the private section. 
*/
private:
	float mass;
	float surfaceArea;
	float bungeeSpringConstant;
	float bungeeUnstretchedLength;

	/*
	Set g equal to 9.81 as instructed. 
	*/
	float g = 9.81;

	/*
	Initialize the variables that will be calculated. 
	*/
	float distance = 0;
	float velocity = 0;
	float acceleration = 0;

};

/*
Make a function specific to the class FallingObject with arguments of the variables that will be 
used in the calculation process. 
*/
FallingObject::FallingObject(float mass, float surfaceArea, float bungeeSpringConstant, float bungeeUnstretchedLength) {

	/*
	Use the this pointer to make the private variables from the class equal to the arguments 
	respectively set in the void simulateBungeeJump() function. 
	*/
	this-> mass = mass;
	this-> surfaceArea = surfaceArea;
	this-> bungeeSpringConstant = bungeeSpringConstant;
	this-> bungeeUnstretchedLength = bungeeUnstretchedLength;
}

/*
Using the public get functions from the class, I made function calls direct to the class in order to 
return the private variables without anyone being able to publically change the variable values. 
The get functions are then able to access the class and its private sections and be able to return the 
private variables whose values were given values using the this pointer in the case of mass, surface 
area, bungee spring constant, and bungee unstretched length. The other variables like velocity and 
acceleration are returned using their respective public get function to return the private variable
in order to be calculated for and be used in calculation. 
*/
float FallingObject::getMass() {
	return mass;
}

float FallingObject::getSurfaceArea() {
	return surfaceArea;
}

float FallingObject::getBungeeSpringConstant() {
	return bungeeSpringConstant;
}

float FallingObject::getBungeeUnstretchedLength(){
	return bungeeUnstretchedLength;
}

float FallingObject::getGravity(){
	return g;
}

float FallingObject::getDistance(){
	return distance;
}

float FallingObject::getVelocity(){
	return velocity;
}

float FallingObject::getAcceleration(){
	return acceleration;
}

/*
As instructed, the FallObject class will also have a void function used for updating the acceleration, 
velocity, and distance using deltaT as an argument as shown in the sample code of the assignment.
The deltaT value and simulationTime values were all taken from the assignment doc in which its under
the void simulateBungeeJump() function. 
*/
void FallingObject::simulateTimestep (float time) {

	/*
	Declare the 4 different force variables needed for the calculations. 
	*/
	float force_g, force_fric, force_spring, force_total;

	/*
	Set the force variables equal to their respective formulas based on the assignment doc and calculate
	for each force variable. 
	*/
	force_g = mass * g;
	force_fric = (-0.65)*surfaceArea*velocity*abs(velocity);

	/*
	Initialize the spring force variable before entering as part of the if statement calculation.
	*/
	force_spring = 0;

	/*
	Using an if statement, check if the distance is greater than the bungee unstretched length in
	which case, the force of the spring would then be equal to its formula with d equaling the distance
	minus the bungee unstretched length because it is a calculation of how much the spring stretched. 
	*/
	if (distance > bungeeUnstretchedLength) {

		force_spring = -21.7 * (distance - bungeeUnstretchedLength);

	}

	/*
	Set the total force to equal the sum of the three forces mentioned in the assignment doc. 
	*/
	force_total = force_g + force_fric + force_spring;

	/*
	The acceleration is then set equal to the total force divided by the mass as shown in the assignment
	doc. 
	*/
	acceleration = force_total / mass;

	/*
	To update the velocity, the velocity is concatenated so that the new velocity is equal to the formula
	given on the assignment doc of acceleration multiplied by deltaT except adding the old velocity to 
	that to get the new velocity. 
	*/
	velocity += acceleration * time;

	/*
	To update the distance, the distance is concatenated so that the new distance is equal to the formula
	given on the assignment doc with velocity multiplying by deltaT except this time adding the old 
	distance to that product to get the updated distance. 
	*/
	distance += velocity * time;
}

/*
Make the void simulateBungeeJump() function as shown in the sample code. This part is mostly the sample
code copied and rearranged and modified. 
*/
void simulateBungeeJump() {

	/*
	Arguments in Order:

	mass (70kg)
	surface area (0.2m^2)
	spring constant for the bungee cord (21.7)
	unstretched length of bungee cord (30m)

	The function call's argument values are set to numeric values that will go through the function above
	and produce calculated results by being becoming the values for the private variables.
	*/
	FallingObject fallingObject(70.0f, 0.2f, 21.7f, 30.0f);

	/*
	Make vectors of floating points as shown in the sample code to collect each elapsed time, distance,
	velocity, and acceleration respectively for each time step. 
	*/
	vector<float> elapsedTimes;
	vector<float> distances;
	vector<float> velocities;
	vector<float> accelerations;

	/*
	In the case when time step is zero.
	*/
	elapsedTimes.push_back(0.0f);
	distances.push_back(fallingObject.getDistance());
	velocities.push_back(fallingObject.getVelocity());
	accelerations.push_back(fallingObject.getAcceleration());

	/*
	As shown in the sample code, the time steps is set equal to the simulation time divided by deltaT.
	*/
	float simulationTime = 60; // 60 seconds
	float deltaT = 0.01;       // 0.01 seconds
	int timeSteps = (int)(simulationTime / deltaT);

	/*
	Make a for loop which will loop starting at t = 1 until t is one integer less than the time steps
	in which case time in the simulateTimestep function will have deltaT's value passed into it. 
	*/
	for (unsigned int t = 1; t < timeSteps; t++) {
		fallingObject.simulateTimestep(deltaT);

		/*
		Push back the elapsed time vector so its index goes to deltaT times the countet t to go 
		through the time steps.
		*/
		elapsedTimes.push_back(deltaT * t);

		/*
		Push back the distance, velocity, and acceleration vectors respectively with an index equal to
		the get function direct to the class while looping to go through the updating distances, 
		velocities, and accelerations.
		*/
		distances.push_back(fallingObject.getDistance());
		velocities.push_back(fallingObject.getVelocity());
		accelerations.push_back(fallingObject.getAcceleration());
	}

	/*
	Make a for loop in which it will print all the elapsed times, distances, velocities, and accelerations
	set for their vectors indexes to equal the counter to print every updated value for each time step.
	*/
	for (int j = 0; j < elapsedTimes.size(); j++) {

		cout << "Elapsed Times: " << elapsedTimes[j] << " " << "Distances: " << distances[j] << " " << "Velocities: " << velocities[j] << " " << "Accelerations: " << accelerations[j] << endl;

	}
}

//Part 2 - Greedy Algorithm
/*
Make the class Process.
*/
class Process {

/*
Make the get functions to be within the public section in order to access the private variables later on
similar to Part 1. Also, make a function call in which the function Process can take two arguments 
that will be connected. 
*/
public:
	Process(double duration, double requiredEndTime);
	double getDuration();
	double getStartTime();
	double getRequiredEndTime();

	/*
	Make another function as instructed for the start time using the start time as an argument.
	*/
	void setStartTime(double startTime);

/*
Set the three variables of Part 2 as private variables that need to be accessed using get functions
as instructed. 
*/
private:
	double duration;
	double startTime;
	double requiredEndTime;
};

/*
Make a function call for the function Process direct to the class Process with its two arguments being
duration and required end time which are given numeric values from the counter from for loops. These 
values will be set equal to the private variables using the this pointer. 
*/
Process::Process(double duration, double requiredEndTime) {
	this-> duration = duration;
	this-> requiredEndTime = requiredEndTime;
}

/*
Make the get functions direct to the class Process respectively for each of the two variables of 
duration and required end time to be able to access the private variables in the public section. 
*/
double Process::getDuration(){
	return duration;
}
double Process::getRequiredEndTime(){
	return requiredEndTime;
}
double Process::getStartTime() {
	return startTime;
}

/*
Make the get function direct to the class Process for the start time variable to be able to access and
equal the private start time in the public section.
*/
void Process::setStartTime(double startTime){
	this-> startTime = startTime;
}

/*
As shown in the sample code, make a integer function that takes the vector of Process class results.
*/
int getMinimumEndTime(vector<Process> Processes) {

	/*
	Set a variable for index to equal zero which could equal the counter i if the Processes vector 
	integer value at index "index" is greater than that of index "i".
	*/
	int index = 0;

	/*
	Make a for loop to go through the Processes vector.
	*/
	for (unsigned int i = 1; i < Processes.size(); i++) {

		/*
		In this case, set index to equal i 
		*/
		if (Processes[i].getRequiredEndTime() < Processes[index].getRequiredEndTime()) {
			index = i;
		}
	}

	/*
	Return the new index value. 
	*/
	return index;
}

/*
As shown in the sample code, make a vector function of class Process results that takes in the Processes
vector as an argument.
*/
vector<Process> scheduleProcesses(vector<Process> Processes) {

	/*
	Make a new variable for the total time and initialize it.
	*/
	int netTime = 0;

	/*
	Declare the vector of Process results.
	*/
	vector<Process>  VectorOfProcesses;

	/*
	Make an integer variable equal to the size to the Processes vector. 
	*/
	int size = Processes.size();

	/*
	Make a for loop that loops to the size of the Processes vector. 
	*/
	for (int i = 0; i < size; i++){

		/*
		Set an integerto equal the getMinimumEndTime function with the index being the vector Processes. This obtains the process with the minimum required time. 
		*/
		int reqTimeIndex = getMinimumEndTime(Processes);			

		/*
		In order to check if the index of process before the required end time is larger than the sum of the time passed with the required time.
		*/
		if (Processes[reqTimeIndex].getRequiredEndTime() >= Processes[reqTimeIndex].getDuration() + netTime){		

			/*
			Make the process start time equal to the total time.
			*/
			Processes[reqTimeIndex].setStartTime(netTime);				

			/*
			Concatenates so that the total time will be the total time is equal to the old total time plus the time that passed.
			*/
			netTime += Processes[reqTimeIndex].getDuration();		

			/*
			Push the vector of processes into a different vector.
			*/
			VectorOfProcesses.push_back(Processes[reqTimeIndex]);		

			/*
			Erase the process results from the previous vector. 
			*/
			Processes.erase(Processes.begin() + reqTimeIndex);														
		}

		/*
		In every other case, the process is not the minimum time and so the process is erased. 
		*/
		else
			Processes.erase(Processes.begin() + reqTimeIndex);														
	}
	/*
	Return the modified vector. 
	*/
	return VectorOfProcesses;
}

/*
Main function
*/
int main()
{
	/*
	Make the function call to main.
	*/
	simulateBungeeJump();

	/*
	Declare the processes vector.
	*/
	vector<Process> processes;

	/*
	Make various instances for the Process class.
	*/
	Process p1(5, 11);
	Process p2(5, 5);
	Process p3(7, 15);
	Process p4(6, 19);
	Process p5(8, 9);

	/*
	Push back the various Process class instances into the processes vector. 
	*/
	processes.push_back(p1);
	processes.push_back(p2);
	processes.push_back(p3);
	processes.push_back(p4);
	processes.push_back(p5);

	/*
	Make a new line for neatness.
	*/
	cout << endl;

	/*
	Declare the new vector that is equal to the processes vector entering the function scheduleProcesses. 
	*/
	vector<Process> scheduled = scheduleProcesses(processes);

	/*
	Make a for loop to loop as much as the size of the new vector. Print out each of the results just as shown in the sample code. 
	*/
	for (unsigned int i = 0; i < scheduled.size(); i++) {
		cout << scheduled[i].getStartTime() << " - ";
		cout << (scheduled[i].getStartTime() + scheduled[i].getDuration()) << endl;
	}

	system("pause");
	return 0;
}