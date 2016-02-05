#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Naive Method is to apply merge sort and arrange all characters
	
	Efficient Method 1
	- Take 2 unsigned (32 bit) integer & set bits in integers according to string char one by one
*/




void check(char ch, unsigned int *number){
	int x;
	x = (int)ch - 97;
	*number = (*number)|(1<<x);	
}

int main(void )
{	
	char str[100], str2[100] ;
	
	unsigned int number1 = 0;
	unsigned int number2 = 0;
	
	strcpy(str,"tttt");
	
	strcpy(str2,"tttt");
	
	for(int i =0 ; str[i]!='\0'; i++)
	{		
		check( str[i],  &number1 );
		check( str2[i], &number2 );
	} 
	
	if(number1==number2)
		printf("string is anagram");
	else
		printf("string is not anagram");

	return 0;
}
