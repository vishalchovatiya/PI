#include<iostream>
#include <queue>
#include <map>

using namespace std;

/*
	Question:- Find the largest rectangle of 1’s with swapping of columns allowed

	Example:- 
	
	0 1 0 1 0
	0 1 0 1 1
	1 1 0 1 0

	Step 1: First of all, calculate no. of consecutive 1’s in every column.

	0 1 0 1 0
	0 2 0 2 1
	1 3 0 3 0
	
	Step 2: Find heighest no in term of its frquency in each row, let say x
	
	Step 3: Check if there is any no above x then increament the x's frequency by 1
	
	Step 4: Repeat this process for all rows in find maximum among this which is answer
*/

#define N	5

void printMatrix(int M[][N])
{
	for(int i=0; i<N; i++)
    {
    	for(int j=0; j<N; j++)
        	cout << M[i][j] << " ";
    	cout << endl;
    }
    cout << endl;
    cout << endl;
}

int largestRectangle( int M[][N])
{
	int ProcessMatrix[N][N];
	int Answer = 0;
	
	// Step 1: First of all, calculate no. of consecutive 1’s in every column.
	for(int i=0; i<N; i++)
    {
    	int count = 1;
    	
    	for(int j=0; j<N; j++)
        {        	
        	ProcessMatrix[j][i] = 0;
        	
        	if( M[j][i] == 1 )
        		ProcessMatrix[j][i] = count++;
        	else	
        		count = 1;
        }
    }
    
    // Step 2: Find heighest no in term of its frquency in each row, let say x
    for(int i=0; i<N; i++)
    {
    	int MostRepeatedNo = 0;
  		int MostRepeatedNoFreq = INT_MIN;
			
		map<int,int>  	freq;
		
    	for(int j=0; j<N; j++)
        {			
			if( ProcessMatrix[i][j] != 0 
			&&  ++freq[ ProcessMatrix[i][j] ] 
			&&  freq[ ProcessMatrix[i][j] ] > MostRepeatedNoFreq )
			{
				MostRepeatedNo = ProcessMatrix[i][j];
				MostRepeatedNoFreq = freq[ ProcessMatrix[i][j] ];
			}
        }
        // Step 3: Check if there is any no above x then increament the x's frequency by 1
        for(int k=0; k<N; k++)
        {
        	if( ProcessMatrix[i][k] > MostRepeatedNo )
        		MostRepeatedNoFreq++;
        }
        // Step 4: Repeat this process for all rows in find maximum among this which is answer
        Answer = max(Answer, MostRepeatedNo * MostRepeatedNoFreq);
    }

    return Answer;
}

int main()
{
	int M[][N] =   { {0, 1, 0, 1, 0},
            		 {0, 1, 1, 1, 1},
                     {1, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1},
                     {1, 0, 1, 0, 1}};
	            
	printMatrix( M);
				    
	cout<<largestRectangle( M);   
 
    return 0;
}
