#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*
	Input:- 54, 546, 548, 60 
	Output:- 6054854654 
	
	Input:- 1, 34, 3, 98, 9, 76, 45, 4
	Output:- 998764543431

	Algo:- 
	
	- Store no in string array
	- Compare string by Ascii char value in lexicographical order
	
	- Ready made method to compare string is strcmp & string class's method compare
*/

bool Compare( string X, string Y)
{
	string XY = X.append(Y);
	
	string YX = Y.append(X);
	
	return ( XY.compare(YX) > 0 ? 1 : 0 );
}

void FormGreatestNo(vector<string> Arr)
{
	stable_sort( Arr.begin(), Arr.end(), Compare );
	
	vector<string> :: iterator it;
	for( it=Arr.begin(); it!=Arr.end(); it++)
	{
		cout<<*it;
	}
}

int main()
{
	vector<string> Arr;
	
	Arr.push_back("7");
    Arr.push_back("776");
    Arr.push_back("7");
    Arr.push_back("7");

	FormGreatestNo( Arr);

	return 0;
}


