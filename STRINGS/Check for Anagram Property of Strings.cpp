#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Naive Method is to apply merge sort and arrange all characters
	
	Efficient Method 1 is sum all character
	
	Efficient Method 2
	1) Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
	2) Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
	3) Compare count arrays. If both count arrays are same, then return true.
*/

int main()
{
	char String1[101];
	char String2[101];
	
	
	long long Str1 = 0, Str2 = 0;
	
	memset(String1, 0, sizeof(String1));
	memset(String2, 0, sizeof(String2));
	
	gets(String1);
	//cout<<String1<<endl;
	gets(String2);
	//cout<<String1<<endl;
	
	if( strlen(String1) == strlen(String2) )
	{
		int idx = 0;
		while( String1[idx] != '\0' && String2[idx] != '\0' )
		{
			Str1 = Str1 + String1[idx];
			Str2 = Str2 + String2[idx];
			idx++;
		}
		
		if( Str1 == Str2)
		{
			cout<<"yes";
			return 0;
		}

	}

	cout<<"no";


	
	return 0;
}
