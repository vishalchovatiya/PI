#include<cstdio>

#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;


#define TOTAL_JOBS	 5


typedef struct 
{
	char Name;
	int Deadline;
	int Profit;	
}Job;

int compare(const void *a, const void*b)
{
	return ((Job*)a)->Profit < ((Job*)b)->Profit;
}



void maxProfitSequenceOfJobs(Job Jobs[], int Size)
{
	qsort( Jobs, Size, sizeof(Job), compare);
	
	for(int i=0; i<Size; i++)
		cout<<Jobs[i].Name<<" "<<Jobs[i].Deadline<<" "<<Jobs[i].Profit<<endl;
	cout<<"\n\n\n"<<endl;
		
	Job result[Size]; // To store result (Sequence of jobs)
    bool slot[Size];  // To keep track of free time slots
 
    // Initialize all slots to be free
    memset( slot, 0, sizeof(slot));
 
    // Iterate through all given jobs
    for (int i=0; i<Size; i++)
    {
       // Find a free slot for this job (Note that we start from the last possible slot)
       for (int j=min(Size, Jobs[i].Deadline)-1; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = Jobs[i];  // Add this job to result
             slot[j] = true; // Make this slot occupied
             break;
          }
       }
    }

    // Print the result
    for (int i=0; i<Size; i++)
       if (slot[i])
    		cout<<result[i].Name<<" "<<result[i].Deadline<<" "<<result[i].Profit<<endl;
}

int main()
{
	Job Jobs[TOTAL_JOBS] = {{'A', 2, 100}, 
							{'B', 1, 19}, 
							{'C', 2, 27},
		                    {'D', 1, 25}, 
							{'E', 3, 15}};
			
	
	maxProfitSequenceOfJobs( Jobs, TOTAL_JOBS);
	
	return 0;
}
