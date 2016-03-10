#include <stdio.h>

#define 	MAX 	40

/*

	Question:- 
	
	- There are N stones placed on a shallow river to help people cross the river. 
	- The stones are placed in such a way that a person can jump from one stone to the next one, or skip one and jump to the one after that. 
	- Find the number of ways in which one can jump across the stones from one river bank to another. 
	
	Assume first stone is always used.
	
	Input: Number of stones: N
	
	Output: Number of ways.
	
	Constrains: 1<N<40	
	
	Example: 
	
	- If N=2, you can hop to bank directly from stone 1 or step to stone 2 and then to bank. 
	- Thus, there are two ways to cross a river that needs 2 stones
	
	Answer:-
	
	- start with smaller problem of no stone to one stone
	- take step one step( step -1) and skip stone (step-2)
	- each time we step ahead we have new problem 
	- so these small problems lead us to final optimal solution
	
*/

/*------------------------------------Sample Test Cases

		Test Case 1 :
		
		1		
		1
		
		Test Case 2 :
		
		2	
		2
		
		Test Case 3 :
		
		3	
		3
		
		Test Case 4 :
		
		10		
		89
		
		Test Case 5 :
		
		5	
		8

*/

void getWays(int nSteps,int ways[]) 
{
	ways[0] = 1;
	ways[1] = 1;
	
  	for(int Steps=2; Steps<=nSteps; Steps++)
  	{
  		ways[Steps] = ways[Steps-1] + ways[Steps-2];
  	}
}


int main() 
{
	int nSteps;
	int ways[40];
	
    scanf("%d",&nSteps);
        
	getWays(nSteps,ways);
	
	printf("%d",ways[nSteps]);
	
	return 0;
}


