
#include<stdio.h>
#define MAXSIZE 20


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*

	- Use only in sorted array
	- After every iteration we divide search space in half
	- Time Complexity O(LogN)
	

*/


int BinarySearch(int A[], int Size, int Element)
{	// 1, 2, 3, 4, 5, 6, 7, 8
	int start = 0;
	int end = Size-1;
	
	while(start <= end)
	{
		int mid = (start+end)/2	;
		//cout<<" mid = "<<mid<<" start = "<<start<<" end = "<<end<<endl;
		if( A[mid] == Element )	return mid;
		
			else if( A[mid] < Element )	start = mid+1;
		
		else end = mid-1;			
	}
	return -1;
}


int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};
  	int NumIndex = BinarySearch( A, SIZE(A), 6);
  	printf("%d", A[NumIndex]);
	return 0;
}
