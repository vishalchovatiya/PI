#include<iostream>
#include<stdlib.h>
#include <float.h>
#include<math.h>

using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Time Complexity:-
	

	- Let Time complexity of above algorithm be T(n). 
	- Let us assume that we use a O(nLogn) sorting algorithm. 
	- The algorithm divides all points in two sets and recursively calls for two sets. 
	- After dividing, it finds the strip in O(n) time. Also, it takes O(n) time to divide the Py array around the mid vertical line. 
	- Finally finds the closest points in strip in O(n) time. So T(n) can expressed as follows

		T(n) = 2T(n/2) + O(n) + O(n) + O(n)
		T(n) = 2T(n/2) + O(n)
		T(n) = T(nLogn)	
*/

struct Point
{
	int x;
	int y;	
};

int compareX(const void *a, const void *b)
{
	return ( ((Point*)a)->x - ((Point*)b)->x );
}

int compareY(const void *a, const void *b)
{
	return ( ((Point*)a)->y - ((Point*)b)->y );
}

inline float MIN(float x, float y)
{
	return ( x > y) ? y : x;
}




float dist(Point P1, Point P2)
{	
	return sqrt( (P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));
}



float BruteForce(Point P[], int Size)
{
	float distance = FLT_MAX;
	
	for(int i=0; i<Size; i++)
	{
		for(int j=i+1; j<Size; j++)
		{
			distance = MIN( distance, dist( P[i], P[j]));
		}
	}
	
	return distance;
}

float StripClosest( Point Strip[], int StripSize, float D)
{
	qsort( Strip, StripSize, sizeof(Point), compareY);
	
	float Min = FLT_MAX;
	
	for(int i=0; i<StripSize; i++)
		for(int j=i+1; j<StripSize && ( Strip[j].y - Strip[i].y) < Min; j++)
			Min = MIN( Min, dist( Strip[j], Strip[i]));
			
	return Min;		
}

float ClosestPairUtil( Point P[], int Size)
{
	if( Size <= 3)
		return BruteForce( P, Size);
		
	int Mid = Size/2;
	Point MidPoint = P[Mid]	;
	
	float Dl = ClosestPairUtil( P,  Mid);
	float Dr = ClosestPairUtil( P+Mid, Size - Mid);
	
	float D = MIN( Dl, Dr);
	
	Point Strip[Size];
	int StripSize = 0;
	
	
	for(int i=0; i<Size; i++)	
	{
		if( abs(P[i].x - MidPoint.x) < D )
		{
			Strip[i] = P[i];
			StripSize++;
		}
	}
	
	return MIN( D, StripClosest( Strip, StripSize, D));
}

float ClosestPoints(Point P[], int Size)
{
	qsort( P, Size, sizeof(Point), compareX);
	
	return ClosestPairUtil( P, Size);
}


int main()
{
	Point P[] =  {{2, 2}, {12, 30}, {40, 50}, {1, 2}, {12, 10}, {3, 4}};

    
    printf("The smallest distance is %f ", ClosestPoints(P, SIZE(P)));
	
	return 0;
}
