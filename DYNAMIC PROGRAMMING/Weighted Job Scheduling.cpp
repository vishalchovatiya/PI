#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;


#define SIZE(A) 	sizeof(A)/sizeof(A[0])

/*
	Question:- Given N jobs where every job is represented by following three elements of it.

    Start Time
    Finish Time
    Profit or Value Associated

	Find the maximum profit subset of jobs such that no two jobs in the subset overlap. 
	
	Example:-
	
	{1, 2}  {3, 5}  {6, 19}  {2, 100}
	  50      20      100       200
	  
	 Algorithm:-
	 
	 1) First sort jobs according to finish time in ascending order.
	 2) Now initialize array of profit with initial profit.
	   
	   - Start with 1 job
	   - if there is only one job then maximum profit would be
	   - if there is only two(non-overlapping) job then maximum profit would be
	   - if there is only three(non-overlapping) job then maximum profit would be
	   - repeat this process & find maximum out of all
	   
	 Formula:- Profit[i]  =  Profit[ P[i-1] ] + P[i]
*/

typedef struct 
{
	int Start;
	int Finish;
	int Profit;	
}Job;


int CompareFinishTime( const void *a, const void *b)
{
	return ((Job*)a)->Finish > ((Job*)b)->Finish;
}

int maxProfitSubset( Job Jobs[], int Size)
{
	qsort( Jobs, Size, sizeof(Job), CompareFinishTime);
	
	int Profit[Size];
	memset( Profit, 0, sizeof(Profit));
	
	int MaxProfit = 0;
		
	for(int i=0; i<Size; i++)
	{
		Profit[i] = Jobs[i].Profit;
		cout<<" "<<Profit[i];		
	}
//	{1, 2}  {3, 5}  {6, 19}  {2, 100}
//	  50      20      100       200	
	for( int i=0; i<Size; i++)
	{
		for( int j=0; j<i; j++)
		{
			if( Jobs[j].Finish <= Jobs[i].Start )
			{
				Profit[i] += Profit[j];
			}				
		}
		
		MaxProfit = max( MaxProfit, Profit[i]);
	}
	
	return MaxProfit;
}


int main()
{
	Job Jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	
	cout<<maxProfitSubset( Jobs, SIZE(Jobs))<<endl;
	
	return 0;
}
