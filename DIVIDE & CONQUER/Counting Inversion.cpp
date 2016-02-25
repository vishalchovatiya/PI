#include<iostream>

using namespace std;

#define SIZE(N)	(sizeof(N)/sizeof(N[0]))

#define MAX(A,B)	(A>B? A:B)

/*
	Method: Divide & Conquer
	
	Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
	If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
	Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j Example:
	The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

*/

int Merge(int A[], int temp[], int L_Size, int R_Size)
{	// 2, 1
	int i = 0, j = 0, k = 0;
	int Count = 0;
	
	while( i<L_Size && j<R_Size)
	{
		if( A[i] < A[j + L_Size] )
		{
			temp[k] = A[i];
			i++;
			
		}
		else
		{
			temp[k] = A[L_Size + j];
			j++;
			Count++;
		}
		k++;
	}
	
	while( i < L_Size )
	{
		temp[k] = A[i];
		i++;
		k++;
	}
	
	while( j < R_Size)
	{
		temp[k] = A[L_Size + j];
		j++;
		k++;
	}
	
	return Count;
}


int InversionCount(int A[], int Size)
{
	if(Size == 1)	return 0;
	
	int Half = Size/2;
	int temp[Size];
	
	int L_Count = InversionCount( A, Half);
	int R_Count = InversionCount( A+Half, Size - Half);
	int Count = Merge( A, temp, Half, Size-Half);
	
	for(int i=0; i<Size; i++)
		A[i] = temp[i];
	
	return	Count + L_Count + R_Count;
}


int main()
{
	int A[] = { 1, 20, 6, 4, 5};
	
	cout<<InversionCount( A, SIZE(A))<<endl;
	
	for(int i=0; i<SIZE(A); i++)
		cout<<" "<<A[i];
	
	return 0;
}
