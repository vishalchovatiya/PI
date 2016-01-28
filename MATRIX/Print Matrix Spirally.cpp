#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEFT_TO_RIGHT 0
#define TOP_TO_BOTTOM 1
#define RIGHT_TO_LEFT 2
#define BOTTOM_TO_TOP 3

/*
Top		1  2  3  4				  
		5  6  7  8
		9  10 11 12
Bottom	13 14 15 16
		Left      Right
	
	Output for the above matrix: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
	
	INPUT:
	
		First line contains two integers M and N separated by whitespace. 
		The next M lines contain elements of matrix A, starting with the topmost row. 
		Within each row, the elements are given from left to right.
	
	OUTPUT:
	
		Elements of the matrix printed in a spiral order. All the elements should be separated by whitespace.
	
	CONSTRAINTS:
	
		1 <= M <= 5, 1 <= N <= 5.
		
		Elements in the matrix will be in the range [-100,100]	
*/

void PrintMatrix(int **Matrix, int Rows, int Columns)
{
	int i=0, j=0;
	for(i=0; i<Rows; i++)
	{
		for( j=0; j<Columns; j++)
			printf("%4d", Matrix[i][j]);
		printf("\n");
	}
	printf("\n");	
}

int** AllocateMatrix( int Rows, int Columns)
{
	int **Matrix, i;
	
  	Matrix = (int**)malloc(Rows * sizeof(int*));
	
	for( i=0; i<Rows; i++)
	{
		Matrix[i] = (int*)malloc(Columns*sizeof(int));      
		memset( Matrix[i], 0, sizeof(int) * Columns);
	}	
		
	return	Matrix;
}

void GetMatrixData(int **Matrix, int Rows, int Columns)
{	
	int i=0, j=0;
	for(i=0; i<Rows; i++)
	{		
		for(j=0; j<Columns; j++)
		{
          	scanf("%d", &Matrix[i][j]);
		}
	}		
}


void PrintMatrixSpirally(int **Matrix, int Row, int Column)
{
	int i = 0;
	int T = 0, B = Row-1;		// Top & Bottom
	int L = 0, R = Column-1;	// left & Right
	int Dir = LEFT_TO_RIGHT;
	
	while( L <= R && T <= B )
	{
		if( Dir == LEFT_TO_RIGHT )	
		{
			for( i=L; i <= R; i++)
				printf(" %d",Matrix[T][i]);
			T++;
			Dir = TOP_TO_BOTTOM;
		}
		else if( Dir == TOP_TO_BOTTOM )	
		{
			for( i=T; i <= B; i++)
              	printf(" %d",Matrix[i][R]);
			R--;	
			Dir = RIGHT_TO_LEFT;
		}
		else if( Dir == RIGHT_TO_LEFT )	
		{
			for( i=R; i >= L; i--)
              	printf(" %d", Matrix[B][i]);
			B--;
			Dir = BOTTOM_TO_TOP;	
		}
		else if( Dir == BOTTOM_TO_TOP )	
		{
			for( i=B; i >= T; i--)
              	printf(" %d", Matrix[i][L]);
			L++;
			Dir = LEFT_TO_RIGHT;	
		}
	}
}

int main()
{
	int **Matrix1, Row1 = 0, Column1 = 0 ;
	
	scanf("%d %d", &Row1, &Column1);

	Matrix1 = AllocateMatrix( Row1, Column1);
	GetMatrixData( Matrix1, Row1, Column1);	

	PrintMatrixSpirally( Matrix1, Row1, Column1);
	
	return 0;
}

