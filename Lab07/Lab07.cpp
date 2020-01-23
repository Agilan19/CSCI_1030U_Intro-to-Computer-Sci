// Lab07.cpp : Defines the entry point for the console application.
// Name: Agilan Ampigaipathar (100553054)
// Date: March 22, 2015
// Lab 07 - Object-Oriented Programming
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define PI 3.14159265358979323846

using namespace std;

//Make a class for Rectangle which represents a rectangle shape.
class Rectangle {

//The variables to be used within the class are public so they can be accessed elsewhere.
public:
	//Make the variables float as instructed.
	float width;
	float height;

	//Make the area and perimeter variables double for more accuracy.
	double area;
	double perimeter;

	//Make a function call of the class with the float variables as the arguments.
	Rectangle(float width, float height);

	//Declare the functions to be used specific to the Rectangle class. 
	double getArea();
	double getPerimeter();
};

//Make a Circle class which represents a circle shape.
class Circle {

//The variables to be used within this class are also publicso they can be accessed elsewhere.
public:

	//Declare the variable for radius as a float variable as instructed. 
	float radius;

	//Make the area and perimeter variables double for more accuracy.
	double area;
	double perimeter;

	//Make a function call of the class with the float radius as an argument.
	Circle(float radius);

	//Declare te functions to be used specific to the Circle class. 
	double getArea();
	double getPerimeter();
};

/*
Make a function call linked directly to the Rectangle class in which the 
arguments are that of the Rectangle class. 
*/
Rectangle::Rectangle(float width, float height) {

	//Initiate the area and perimeter variables for this function of the class.
	area = 0.0;
	perimeter = 0.0;
}

//Calculate the area within the getArea function specific to the Rectangle class. 
double Rectangle::getArea() {

	//Calculate the area using the formula given on the assignment document.
	double area = (width * height);

	/*
	Return the variable back so the Rectangle class function call so it could return the 
	calculation. 
	*/
	return area; 
}

//Calculate the perimeter within the getPerimeter function specific to the Rectangle class.
double Rectangle::getPerimeter() {

	//Calculate the perimeter using the formula given on the assignment document.
	double perimeter = ((width * 2) + (height * 2));
	
	/*
	Return the variable back to the Rectangle class function call so it could return the 
	calculation. 
	*/
	return perimeter;
}

/*
Make a function call linked directly to the Circle class in which the
arguments are that of the Circle class.
*/
Circle::Circle(float radius) {

	//Initiate the area and perimeter variables for this function of the class.
	area = 0.0;
	perimeter = 0.0;
}

//Calculate the area within the getArea function specific to the Circle class. 
double Circle::getArea() {

	//Calculate the area using the formula given on the assignment document.
	double area = (PI * (radius*radius));

	/*
	Return the variable back so the Circle class function call so it could return the
	calculation.
	*/
	return area;
}

//Calculate the perimeter within the getPerimeter function specific to the Circle class.
double Circle::getPerimeter() {

	//Calculate the perimeter using the formula given on the assignment document.
	double perimeter = (2 * (PI * radius));

	/*
	Return the variable back to the Circle class function call so it could return the
	calculation.
	*/
	return perimeter;
}

//Make a parent class to the classes Rectangle and Circle named Shape.
class Shape : public Rectangle, public Circle {
public:
	
};

int _tmain(int argc, _TCHAR* argv[])
{

	//Make an instance to the Rectangle class and set width and height values.
	Rectangle calculation1 (41.0, 12.4);
	calculation1.width = 41.0; 
	calculation1.height = 12.4;

	/*
	Using the instance variable and its set height and width to enter the 
	getArea function and return the calculated result and then print it. 
	*/
	cout << "The Calculated Area of the Rectangle is: " << calculation1.getArea() << endl;

	//Make another instance to the Rectangle class and set different width and height values. 
	Rectangle calculation2(19.42, 27.19);
	calculation2.width = 19.42;
	calculation2.height = 27.19;

	/*
	Using the instance variable and its new set height and width to enter the
	getPerimeter function and return the calculated result and then print it.
	*/
	cout << "The Calculated Perimenter of the Rectangle is: " << calculation2.getPerimeter() << endl;

	//Make a line space to distinguish between the output for the Rectangle and Circle classes. 
	cout << endl;

	//Make an instance to the Circle class and set a radius value.
	Circle calculation3(35.41);
	calculation3.radius = 35.41;

	/*
	Using the instance variable and its set radius to enter the
	getArea function and return the calculated result and then print it.
	*/
	cout << "The Calculated Area of the Circle is: " << calculation3.getArea() << endl;

	//Make another instance to the Circle class and a different radius. 
	Circle calculation4(21.78);
	calculation4.radius = 21.78;

	/*
	Using the new instance variable and its new set radius to enter the
	getPerimeter function and return the calculated result and then print it.
	*/
	cout << "The Calculated Perimenter of the Circle is: " << calculation4.getPerimeter() << endl;

	//Make a line space to distinguish between Part 2 and 3.
	cout << endl;

	//Make a vector to store the calculated results for the class Rectangle.
	vector <Rectangle> r;

	//Make another vector to store the calculated results for the Circle class.
	vector <Circle> c;

	//Make numerous instances for the Rectangle and Circle classes with different variable values. 
	Rectangle r1(2.1, 3.2);
	r1.width = 2.1;
	r1.height = 3.2;

	Rectangle r2(4.5, 1.5);
	r2.width = 4.5;
	r2.height = 1.5;

	Rectangle r3(41.2, 21.9);
	r3.width = 41.2;
	r3.height = 21.9;

	Circle r4(23.89);
	r4.radius = 23.89;

	Circle r5(47.2);
	r5.radius = 47.2;

	//Push all the Rectangle class instances into vector r.
	r.push_back(r1);
	r.push_back(r2);
	r.push_back(r3);

	//Push all the Circle class instances into vector c. 
	c.push_back(r4);
	c.push_back(r5);

	/*
	Loop so that it runs through each Rectangle class instances within the vector r
	and input them into the getArea and getPerimeter member functions and then print 
	out the results. The program is simply printing the results to test the member 
	functions as instructed. 
	*/
	for (int i = 0; i < r.size(); i++){
		cout << r[i].getArea() << endl;
		cout << r[i].getPerimeter() << endl;
	}

	cout << endl;
	
	/*
	Loop so that it runs through each Circle class instances within the vector c
	and input them into the getArea and getPerimeter member functions and then print
	out the results. The program is simply printing the results to test the member
	functions as instructed.
	*/
	for (int j = 0; j < c.size(); j++) {
		cout << c[j].getArea() << endl;
		cout << c[j].getPerimeter() << endl;
	}

	system("pause");
	return 0;

	/*
	Ouput:

	The Calculated Area of the Rectangle is: 508.4
	The Calculated Perimeter of the Rectangle is: 93.22

	The Calculated Area of the Circle is: 3993.14
	The Calculated Perimeter of the Circle is: 136.848

	6.72
	10.6
	6.75
	12
	902.28
	126.2

	1793.01
	150.105
	6998.97
	296.566
	*/
}

