#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question : Given three points (x1, y1), (x2, y2) and (x3, y3) , write a program to check if all the three points fall on one straight line.

	INPUT: Six integers x1, y1, x2, y2, x3, y3 separated by whitespace.
	
	OUTPUT: Print “Yes” if all the points fall on straight line, “No” otherwise.
	
	CONSTRAINTS: -1000 <= x1, y1, x2, y2, x3, y3 <= 1000			
*/

int main()
{
	int x1, y1, x2, y2, x3, y3;
	char Cordinates[50];
		
	gets(Cordinates);

	x1 = atoi(strtok(Cordinates, " "));
	y1 = atoi(strtok(NULL, " "));

	x2 = atoi(strtok(NULL, " "));
	y2 = atoi(strtok(NULL, " "));

	x3 = atoi(strtok(NULL, " "));
	y3 = atoi(strtok(NULL, " "));
	
	if( (x1 == x2 && x2 == x3) ||  (y1 == y2 && y2 == y3))
		printf("Yes");
	else	
		printf("No");
	
	return 0;
}

