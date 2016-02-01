#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define BINARY			2
#define DECIMAL			10
#define HEXADECIMAL 	16
#define OCTAL			8



// Set bit
#define SETBIT(integer, x)			(integer | (1<<x-1))

// Claer bit
#define CLEARBIT(integer, x)		(integer & (~(1<<x-1)))

// Toggle bit
#define TOGGLEBIT(integer, x)		(integer ^ ((1<<x-1)))





void PrintBinaryRepresentation(int integer, int base)
{
	int i=33;
	char Binary[i];
	Binary[--i] = '\0';
	
	while( integer > 0)
	{
		Binary[--i] = "0123456789ABCDEF"[integer%base];
		integer /= base;
	}
	
	cout<<&Binary[i]<<endl;
}

int main()
{
	int integer = 7;
	
	integer = CLEARBIT(integer, 3);
	integer = SETBIT(integer, 3);
	integer = TOGGLEBIT(integer, 5);
	
	PrintBinaryRepresentation(integer, BINARY);
	
	
	return 0;
}

