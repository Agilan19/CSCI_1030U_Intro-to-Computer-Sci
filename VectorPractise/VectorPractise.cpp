// VectorPractise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//Not complete, but idea for linearSearch and Minimum Distance

//unsigned int because negative inputted integers could appear in the vector.
bool linearSearch(int elemToFind, vector<int>list, unsigned int startIndex) {

	if (startIndex >= list.size()) {
		return false;
	}

	if (list[startIndex] == elemToFind) {
		return true;
	}
	else {
		//Recursion
		return linearSearch(elemToFind, list, startIndex + 1);
	}
}

int getMinimumDistance(vector<int> list) {
	if (list.size() < 2) {
		return -1; // error
	}

	int minDifference = abs(list[0] - list[1]);
	for (unsigned int i = 0; i < list.size(); i++) {
		for (unsigned int j = 0; j < list.size(); j++) {
			if (i != j) { // don't consider the same element
				if (abs(list[i] - list[j]) < minDifference) {
					minDifference = abs(list[i] - list[j]);
				}
			}
		}
	}

	return minDifference;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> list;
	list.push_back(1);
	list.push_back(5);
	list.push_back(-47);
	list.push_back(57);

	linearSearch(1, list, 5);

	system("pause");
	
	return 0;
}

