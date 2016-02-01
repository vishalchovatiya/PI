#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


bool PowerOfTwo(int X)
{
	if( X && !( X & (X - 1) ) )
		return true;
	
	return false;
}


/*
	Logic:- 

	- First left side of && checks whether X is 0 or not. Right side performs the check for powers of 2.

    - (X-1) flips the least significant standing bit to 0, and flip all zeros that follow that bit to 1.

		Example:
		 (8)  - (1) =  (7)
		1000 - 0001 = 0111 

	- So if you & (X-1) with X you get zero if there is only one standing bit (i.e. powers of two). 
	- This does not work if X is zero, hence left side of && first checks if X is zero.

*/




int main()
{
	int integer = 128;
	
	cout<<PowerOfTwo( integer)<<endl;
	
	return 0;
}

