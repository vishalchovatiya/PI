#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
        Naive Method:- Use power of function of math.h & multiply coefficients
                       Time Complexity :- O(NxN)
                       
        Hornor's Method:- Time Complexity :- O(N)                
	- Horner’s method can be used to evaluate polynomial in O(n) time. 
	- To understand the method, let us consider the example of 2x^3 – 6x^2 + 2x – 1. 
	- The polynomial can be evaluated as ((2x – 6)x + 2)x – 1. 
	- The idea is to initialize result as coefficient of xn which is 2 in this case, 
	- repeatedly multiply result with x and add next coefficient to result. Finally return result.
	
*/

int Horner(int Coefficients[], int N, int X)
{
	int Result = Coefficients[0];
	
	for(int i=1; i<N; i++)
		Result = Result * X + Coefficients[i];
	
	return Result;	
}


int main()
{
	// Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    int poly[] = {2, -6, 2, -1};
    int x = 3;
    int n = sizeof(poly)/sizeof(poly[0]);
    
    cout<<"Value of polynomial is "<<Horner(poly, n, x);
	
	return 0;
}
