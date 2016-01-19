#include <iostream>
#include <string.h>
#include <list>
#include <math.h>
#include <map>
#include <stack>
using namespace std;

/*
	# Game Rules:
	
		1. You can not place a larger disk onto smaller disk
	    	2. Only one disk can be moved at a time

	# Algorithm:
		
		- Shift N-1 disks from Source to Auxiliary
		- Shift last disks from Source to Destination
		- Shift N-1 disks from Auxiliary to Destination
		     
	# Cheat:- Formulating Algo with 2 Disk simulation
	
	- Initial 	- Step 1: Move A to B	- Step 2: Move A to C	- Step 3: Move B to C	- Step 4: Repeat this 3 steps untill 2^N -1 times
		
	1									1
	2________	2___1____		____1___2		________2
	A   B	C	A   B	C		A   B	C		A   B	C
			     
*/


void PrintStack( const char Tittle[], stack<int> &Stack)
{
	cout<<Tittle;
	while( !Stack.empty())
	{
		cout<<" "<<Stack.top();
		Stack.pop();
	}
	cout<<endl;
}


void DisplayOperation(const char Stack1Name[], const char Stack2Name[], int DiskNo)
{
	static int MoveNo = 1;
	printf(" %2d : Move Disk %2d  From %11s To %11s\n", MoveNo++, DiskNo, Stack1Name, Stack2Name);
}


void DiskMovement(const char Stack1Name[], stack<int> &Stack1, const char Stack2Name[], stack<int> &Stack2)
{	
	// If Stack1 is empty 	
	if( Stack1.empty() && !Stack2.empty() )  	
	{
		DisplayOperation( Stack2Name, Stack1Name, Stack2.top());
		Stack1.push(Stack2.top());
		Stack2.pop();
	}
	// If Stack2 is empty 
	else if( Stack2.empty() && !Stack1.empty() )	
	{
		DisplayOperation( Stack1Name, Stack2Name, Stack1.top());
		Stack2.push(Stack1.top());
		Stack1.pop();
	}
	// If Stack1's Disk is smaller than Stack2's
	else if( Stack1.top() < Stack2.top() && !Stack1.empty() )
	{
		DisplayOperation( Stack1Name, Stack2Name, Stack1.top());
		Stack2.push(Stack1.top());
		Stack1.pop();
	}
	// If Stack2's Disk is smaller than Stack1's
	else if( Stack2.top() < Stack1.top() && !Stack2.empty() )
	{
		DisplayOperation( Stack2Name, Stack1Name, Stack2.top());
		Stack1.push(Stack2.top());
		Stack2.pop();
	}	
}


void TowerOfHanoi( int NoOfDisks, const char Stack1Name[], stack<int> *Source, stack<int> *Auxiliary, const char Stack2Name[], stack<int> *Destination)	
{
	if( NoOfDisks == 1 )
	{
		DiskMovement(Stack1Name, *Source, Stack2Name, *Destination);
	}
	else if( NoOfDisks > 1)
	{			
		TowerOfHanoi( NoOfDisks-1 , "Source", Source, Destination, "Auxiliary", Auxiliary);	
		
		DiskMovement(Stack1Name, *Source, Stack2Name, *Destination);

		TowerOfHanoi( NoOfDisks-1 , "Auxiliary", Auxiliary, Source, "Destination", Destination);
	}	
}

int main()
{
	int NoOfDisks = 3;
	
	stack<int> Source;
	stack<int> Destination;
	stack<int> Auxiliary;
		
	for(int Disks = NoOfDisks; Disks>=1; Disks--)
		Source.push(Disks);
	
	TowerOfHanoi( NoOfDisks, "Source", &Source, &Auxiliary, "Destination", &Destination);
	
	PrintStack( "Destination  Stack : ", Destination);
	
	return 0;
}





