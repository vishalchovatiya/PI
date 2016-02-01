#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int NoOfBitsToRepresent(int integer)
{
	int count = 0; 
	while ( integer > 0)
	{
		count++;
		integer /= 2;
	}
	
	return count;
}


int main()
{
	cout<<NoOfBitsToRepresent(16)<<endl;
	
	return 0;
}
