
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX 1000

/*
	Question:- Factorial of Large number
	
	- Factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long long int. 
	- So we use array to store the result
	
	- How to multiply a number ‘x’ with the number stored in res[]?
	
	- The idea is to use simple school mathematics. 
	- We one by one multiply x with every digit of res[]. 
	- The important point to note here is digits are multiplied from rightmost digit to leftmost digit. 
	- If we store digits in same order in res[], then it becomes difficult to update res[] without extra space. 
	- That is why res[] is maintained in reverse way, i.e., digits from right to left are stored.

*/

void Multiply(int Result[], int &ReSize, int X)
{
	int Carry = 0;
	int Product = 0;
	
	for( int i=0; i<ReSize; i++)
	{
		Product = Result[i] * X + Carry;
		
		Result[i] = Product % 10;
		
		Carry = Product / 10;
	}
	
	while( Carry > 0)
	{
		Result[ReSize] = Carry % 10;
		
		Carry = Carry / 10;
		
		ReSize++;
	}
}


void Factorial(int N, int Result[])
{
	int ResultSize = 1;
	Result[0] = 1;
	
	for(int i=1; i<=N; i++)
	{
		Multiply( Result, ResultSize, i);
	}
	
	for(int i=ResultSize-1; i>=0; i--)
		cout<<Result[i];
}

 
int main()
{
	int Result[MAX];
	
	Factorial( 100, Result);
	
	
	cout<<endl;	
	
	return 0;
}


