#include<iostream>

using namespace std;

#define IS_ODD(N)	(N%2)


/*
	Method: Divide & Conquer
	
				  2^4
				/	 \
			2^2		  2^2
		   /	\	/	 \
	    2^1	  2^1 2^1    2^1

*/

int Power(int X, int n)
{
	if( n == 1) return X;
	
	int HalfPow = Power( X, n/2);
	
	if( IS_ODD(n) )
	{
		return X * HalfPow * HalfPow;
	}
	else
	{
		return HalfPow * HalfPow;	
	}
}

int main()
{
	cout<<Power( 3, 5)<<endl;
	
	return 0;
}
