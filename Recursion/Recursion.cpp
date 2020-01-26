// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool vect(vector<int> s1, vector<int> s2){
	int x = s1.size() - 1;
	bool same;
	//Checks to see if both sets are the same size
	if (s1.size() == s2.size()){
		for (int i = 0; i < s1.size(); i++) {
			//Compares the first element in s2 to the last element in s1

			if (s1[x] == s2[i]) {
				same = true;
			}

			//break once any element is not the same
			else{
				same = false;
				break;
			}
			x--;
		}

		//If all elements are the same, then return true
		if (same == true)
			return true;
		//If any element is not the same return false
		else
			return false;

	}
	//If both sets are not the same size, then they are not the same
	else
		return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> s1{ 1, 2, 3 };
	vector<int> s2{ 3, 2, 1 };

	cout << vect(s1, s2) << endl;

	system("pause");
	return 0;

	/*
	Output: 
	
	1
	*/
}
