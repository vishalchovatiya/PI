#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
/*
	Question : At a railway station, we have time-table of trains arrival and departure. We need to find the minimum number of platforms so that all the trains can be accommodated as per their schedule.

				Consider the time to be 24 hours format

	Input: 
	
		- First line contain integer n denoting the number of trains	
		- Second line contains the arrival time of trains (separated by spaces)	
		- Third line contains the departure time of trains
	
	Output:
	
		- Minimum number of platforms so that all the trains are accommodated

	Example:
	
		Input:
		
			3			
			1 2 5			
			4 7 9
		
		Output:
		
			2
			
			
*/

/*---------------Sample Test Cases-------------------------

			
		Test Case 1 :		
					1
					0500
					0600
					
					Answer: 1
		
		Test Case 2 :			
					3
					0200 0300 0600
					0800 0900 0900
					
					Answer: 3
		
		Test Case 3 :						
					5
					0900 0940 0950 1100 1500 
					0910 1200 1120 1130 1900
					
					Answer: 3
		
		Test Case 4 :			
					4
					0100 0300 0005 0050
					0200 0400 0100 0050	
					
					Answer: 2
		
		Test Case 5 :			
					2
					1255 0500
					1600 2200	
					
					Answer: 2
*/

int findPlatform(int arr[], int dep[], int n);

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(){

	int n,count,i;
	scanf("%d",&n);
	
	int * arr = (int*) malloc(n*sizeof(int));
	int * dep = (int*) malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
  	for(i=0;i<n;i++)
		scanf("%d",&dep[i]);
        printf("%d",findPlatform(arr, dep, n));
	return 0;
}


/*
	Naive Approach: Take every interval one by one and find the number of intervals that overlap with it
					-  Time Complexity of this solution is O(n2).

	Effective:
	
		- We can solve the above problem in O(nLogn) time. 
		- The idea is to consider all evens in sorted order. 
		- Once we have all events in sorted order, we can trace the number of trains at any time keeping track of trains that have arrived, but not departed.					

			arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
		    dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
		
		All events sorted by time.
		Total platforms at any time can be obtained by subtracting total 
		departures from total arrivals by that time.
		 Time     Event Type     Total Platforms Needed at this Time                               
		 9:00       Arrival                  1
		 9:10       Departure                0
		 9:40       Arrival                  1
		 9:50       Arrival                  2
		 11:00      Arrival                  3 
		 11:20      Departure                2
		 11:30      Departure                1
		 12:00      Departure                0
		 15:00      Arrival                  1
		 18:00      Arrival                  2 
		 19:00      Departure                1
		 20:00      Departure                0
		
		Minimum Platforms needed on railway station = Maximum platforms 
		                                              needed at any time 
		                                           = 3  	
*/ 
inline int Max(int X, int Y) 
{
	return (X>Y)? X:Y;
}

int findPlatform(int arr[], int dep[], int n)
{
	int result = 0;
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int i=0, j=0;
	int totalPlateForm = 0;
	
	while( i<n && j<n )
	{
		if(  i<n && arr[i] < dep[j] )
		{
			totalPlateForm++;
			i++;
		}
		else
		{
			totalPlateForm--;
			j++;
		}
		
		result = Max( result, totalPlateForm);
	}
	
   	return result;
}
