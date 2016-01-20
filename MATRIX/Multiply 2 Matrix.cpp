#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		A = 3 x 2
		B = 2 x 3
						 ------------------ Internal size match, hence multiplication possible
						|		|
		A * B = 	3 x 2	& 	2 x 3
					|				|
					|				|
					-------------------------Output Matrix Size = 3 x 3
*/

void PrintMatrix(int **Matrix, int Rows, int Columns)
{
	for(int i=0; i<Rows; i++)
	{
		for(int j=0; j<Columns; j++)
			printf("%4d", Matrix[i][j]);
		cout<<endl;	
	}
	cout<<endl;	
}

int** AllocateMatrix( int Rows, int Columns)
{
	int **Matrix;
	
	Matrix = new int*[Rows];
	
	for(int i=0; i<Rows; i++)
	{
		Matrix[i] = new int[Columns];
		memset( Matrix[i], 0, sizeof(int) * Columns);
	}
		
		
	return	Matrix;
}

void GetMatrixData(int **Matrix, int Rows, int Columns)
{
	for(int i=0; i<Rows; i++)
	{		
		for(int j=0; j<Columns; j++)
		{							
			cin>>Matrix[i][j] ;
		}
	}		
}

int** Multiply(int **Matrix1, int Row1, int Column1, int **Matrix2, int Row2, int Column2)
{
	int **Result = AllocateMatrix( Row1, Column2);
	int sum = 0;
	
	for(int i=0; i<Row1; i++)
	{
		for(int j=0; j<Column2; j++)
		{
			sum = 0;
			for(int k=0; k<Column1; k++)
			{
				sum += Matrix1[i][k] * Matrix2[k][j];
			}
			Result[i][j] = sum;
		}
	}
	return Result;
}

int main()
{
	int **Matrix1, Row1 = 0, Column1 = 0 ;
	int **Matrix2, Row2 = 0, Column2 = 0 ;
	
	cout<<"Enter Matrix1 Row :";
	cin>>Row1;
	cout<<"Enter Matrix1 Column :";
	cin>>Column1;
	
	Matrix1 = AllocateMatrix( Row1, Column1);
	
	GetMatrixData( Matrix1, Row1, Column1);	
	
	PrintMatrix( Matrix1, Row1, Column1);
	
	cout<<"Enter Matrix2 Row :";
	cin>>Row2;
	cout<<"Enter Matrix2 Column :";
	cin>>Column2;
	
	// Check similarity for column of 1st matrix and raw of matrix2
	if( Column1 != Row2 )
	{
		cout<<" You can not multiply"<<endl;
		exit(0);
	}		
	
	Matrix2 = AllocateMatrix( Row2, Column2);
	
	GetMatrixData( Matrix2, Row2, Column2);	
	
	PrintMatrix( Matrix2, Row2, Column2);
	
	
	int **Result = Multiply( Matrix1, Row1, Column1, Matrix2, Row2, Column2);

	cout<<"Result = "<<endl;
	PrintMatrix( Result, Row1, Column2);	
	
	return 0;
}
