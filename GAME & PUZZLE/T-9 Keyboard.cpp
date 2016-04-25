#include<string.h>
#include<stdlib.h>
#include<map>
#include<stack>
#include<time.h>
#include<vector>
#include<iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>


using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])

#define DELAY(X)	::Sleep( X /* milliseconds */ );

#define INT_TO_CHAR(X)	X = X-48

#define ROLLED_INCREMENT(X,SIZE)	X = (X+1)%SIZE


/*
	Question:- T-9 KeyBoard
	
	Hint:-
	
	- Use 2D array to Pointer 
	- use library stdio & timer

*/

int getKeyPressed()
{
	static char key_0[3][4]	= {"0", "*.", "*#"};	
	static char key_1[3][4] = {"1","qz","QZ"};
	static char key_2[3][4] = {"2","abc","ABC"};
	static char key_3[3][4] = {"3","def","DEF"};
	static char key_4[3][4] = {"4","ghi","GHI"};
	static char key_5[3][4] = {"5","jkl","JKL"};
	static char key_6[3][4] = {"6","mno","MNO"};
	static char key_7[3][4] = {"7","prs","PRS"};
	static char key_8[3][4] = {"8","tuv","TUV"};
	static char key_9[3][4] = {"9","wxy","WXY"};
	
	static char (*keyPad[])[3][4] = { &key_0, &key_1, &key_2, &key_3, &key_4, &key_5, &key_6, &key_7, &key_8, &key_9  };
	
	int inputType = 0, keyPressed = 0;
	char data = 0;
	int count = 0;
	
	for(;;)
	{
		//keyPressed = getchar();
		keyPressed = _getch();
		fflush(stdin);
		
		switch(keyPressed)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				
				count = 0;
				
				time_t start, current;	
				start = time(NULL); current = start;				
				
				do
				{
					if( kbhit() )
					{
						start = time(NULL);
						keyPressed = _getch();
						fflush(stdin);
			
						ROLLED_INCREMENT(count,3);
					}						
											
					current = time(NULL); 
				}while( difftime(current, start) < 2 /*second*/ );
				
				//cout<<"Key Pressed "<<keyPressed<<endl;
				
				cout<<(*keyPad[INT_TO_CHAR(keyPressed)])[inputType][count]<<endl;								
				
				return 0;
				
				break;
				
			case '*':
				ROLLED_INCREMENT(inputType,3);
				if( inputType == 0 )
					cout<<"Input Type = 123 "<<endl;
				else if( inputType == 1 )
					cout<<"Input Type = abc "<<endl;
				else if( inputType == 2 )
					cout<<"Input Type = ABC "<<endl;	
					
				break;
				
		}
	}
}

 
int main()
{
	getKeyPressed();

    return 0;
}

