#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define SIE(A)		sizeof(A)/sizeof(A[0])

/*
	Question:- Sort Array By frequency	
	
	Answer:- Using STL
	
	- Count Frequency using hash table
	- Pair it & create vector table
	- Sort vector table
	- Rearrange all elements according to its frequency in original list
*/


/*-----------------------------------     Using STL    ----------------------------------*/

bool compare( const std::pair<int,int> &a, const std::pair<int,int> &b)
{
	return ( ( a.second > b.second  )? 1 : 0  );
}

int sortByFrequency(int A[], int Size)
{ // 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8

	map<int, int >						FrequencyTable;
	vector< std::pair<int,int> >		SortingTable;
	
	
	// Counting Frequency 
	for(int i=0; i<Size; i++)
	{
		FrequencyTable[ A[i] ]++;
	}
	
	// Pair it & create vector table
	for( map<int, int> :: iterator it = FrequencyTable.begin(); it!= FrequencyTable.end(); it++ )
	{
		std::pair<int,int>	pairof;
		pairof.first = it->first;
		pairof.second = it->second;
		
		SortingTable.push_back(pairof);		
	}

	// Sort vector table
	std::sort( SortingTable.begin(), SortingTable.end(), compare);
	
	int index = 0;
		
	//Rearrange all elements according to its frequency in original list	
	for( vector< std::pair<int,int> > :: iterator it = SortingTable.begin(); it!= SortingTable.end(); it++ )
	{
		while( it->second > 0 )
		{
			A[index] = it->first;
			
			it->second--;
			index++;
		}
	}	
}

/*---------------------------------------------------------------------------------*/
 
int main()
{	
	int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sortByFrequency(arr, n);
	
	for (int i=0; i<n; i++)
	   cout << arr[i] << " ";
	
	return 0;
}


