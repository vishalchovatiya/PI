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

	PrintBinaryRepresentation(integer, BINARY);
	
	
	return 0;
}

