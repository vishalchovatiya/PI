#include <iostream>
#include <string.h>
#include <list>
#include <math.h>
#include <map>
#include <stack>
using namespace std;

/*

	# Algorithm:
	
			
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

void TowerOfHanoi( int NoOfDisks, stack<int> &Source, stack<int> &Destination, stack<int> &Auxiliary)	
{
	// Total Move Required is 2^N - 1
	int TotalMoveRequired = pow(2, NoOfDisks) - 1;
	
	// Fill the Source Stack with Disks in ascending order
	for(int Disk = NoOfDisks; Disk>=1; Disk--)
		Source.push(Disk);
			
	for(int Move = 1; Move <= TotalMoveRequired; Move++)	
	{
		if( Move % 3 == 1)
			DiskMovement( "Source", Source, "Destination", Destination);
		
		if( Move % 3 == 2)
			DiskMovement( "Source", Source, "Auxiliary", Auxiliary);
		
		if( Move % 3 == 0)
			DiskMovement( "Auxiliary", Auxiliary, "Destination", Destination);	
	}
}

int main()
{
	int NoOfDisks = 10;
	
	stack<int> Source;
	stack<int> Destination;
	stack<int> Auxiliary;
	
	TowerOfHanoi( NoOfDisks, Source, Destination, Auxiliary);
	
	// If No if disks are odd then resultant Stack would be Destination else Auxiliary
	if( NoOfDisks % 2 )
		PrintStack( "Destination  Stack : ", Destination);
	else
		PrintStack( "Auxiliary  Stack : ", Auxiliary);
	
	return 0;
}



