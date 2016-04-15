#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>


using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Centralize the phrase for given line capacity
	
	Algo:
	
	- Copy string in buffer till line capacity 
	- Traverse reverse  until space char appear
*/

void CentralizeInSingleLine(char str[], char Output[], int charInSingleLine)
{
	int strLen = strlen(str);
	int spacing = (charInSingleLine- strLen)/2;
	
	memset( Output, ' ', spacing);
		
	strcat( Output, str);
	
	memset( &Output[spacing+strLen], ' ', spacing);
	
	Output[spacing+strLen+spacing] = '\0';
}

void Centralized(char str[], int charInSingleLine)
{
	char singleLine[charInSingleLine];
	char printBuff[charInSingleLine+1];

	int revCount = 0;
	int printedChar = 0;
	
	for(;;)
	{
		if( strlen(str) < charInSingleLine)
		{
			memset(printBuff, 0, sizeof(printBuff));
			CentralizeInSingleLine( str, printBuff, charInSingleLine);
			cout<<printBuff<<endl;
			return;
		}
		
		strncpy( singleLine, str, charInSingleLine);
	
		revCount = charInSingleLine;
		
		while( revCount != 0 && singleLine[--revCount] != ' ' );
		
		if( revCount == 0 )		revCount = charInSingleLine-1;
		
		singleLine[revCount++] = '\0';
		
		str+= revCount;
		
		memset(printBuff, 0, sizeof(printBuff));
		CentralizeInSingleLine( singleLine, printBuff, charInSingleLine);

		cout<<printBuff<<endl;
	}		
}

 
int main()
{
    char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaThe following solution tries a a a a a a a a a a a a a a a a a every possible                                  subset of half size. If one subset of half size is formed, the remaining elements form the other subset. We initialize current set as empty and one by one build it. There are two possibilities for every element, either it is part of current set, or it is part of the remaining elements (other subset). We consider both possibilities for every element. When the size of current set becomes n/2, we check whether this solutions is better than the best solution available so far. If it is, then we update the best solution.";
    
    int charInSingleLine = 25;
    
    Centralized( str, charInSingleLine);
    
    return 0;
}

