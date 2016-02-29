#include <cstdio>
#define MAX 100
using namespace std;

/*

	A tree is called value balanced tree if for all nodes, sum of values (assume the values are integers) of nodes in left hand side is equal to sum of values in right hand side.
	
	Given a complete binary tree find if it is a value balanced tree or not.
	
	You have to complete isValueBalanced(int [], int) function. You can create other functions but should be called from given function.
	 
	Input Constraints:
	The input tree would be always a complete binary tree.
	
	Input:
	Number of Nodes in first line and values of nodes in level order (as represented as array) in next.
	Output:
	Either “Tree is value balanced” or “Tree is not value balanced”
	
	Sample Test Cases:-

	Test Case 1	
		3
		1 1 1
		Tree is value balanced
	
	Test Case 2	
		7
		3 0 -1 1 1 2 2
		Tree is not value balanced
	
	Test Case 3	
		15
		22 2 4 -3 1 0 -4 4 4 2 2 2 2 4 4
		Tree is value balanced
	
	Test Case 4	
		15
		22 2 2 -5 1 0 -4 4 4 2 2 2 2 4 4
		Tree is not value balanced
	
	Test Case 5	
		15
		22 2 2 -3 1 0 -4 4 4 2 2 2 2 4 4
		Tree is not value balanced
	
 */
bool isValueBalanced(int tree[], int count);



int main() 
{
	int count;
	int tree[MAX];
	
	scanf("%d",&count);
	
	for (int i = 0; i < count; ++i) 
	{
    	    scanf("%d",&tree[i]);
	}
	
	if(isValueBalanced(tree, count)) 
	{
    	   printf("Tree is value balanced");
	} else {
    	   printf("Tree is not value balanced");
	}
	
	return 0;
}

	

#define LEFT_CHILD(X)	2 * X + 1

#define RIGHT_CHILD(X)	2 * X + 2	
	
	
bool isValueBalanced(int tree[], int count)
{
	bool flag = false;
	int sumArr[count];
	int i=0;

	for( i=0; i<count; i++)
		sumArr[i] = tree[i];
	
	
	for( i = count-1; i>=0; i--)
	{
		if( LEFT_CHILD(i) < count )
		{
			sumArr[i] += sumArr[LEFT_CHILD(i)];			
		}
			
		if( RIGHT_CHILD(i) < count )
		{
			sumArr[i] += sumArr[RIGHT_CHILD(i)];
		}
			
		if( LEFT_CHILD(i) < count && RIGHT_CHILD(i) < count && sumArr[LEFT_CHILD(i)] == sumArr[RIGHT_CHILD(i)] )
			flag = true;
		else if(LEFT_CHILD(i) < count && RIGHT_CHILD(i) < count)
			return false;
			
		sumArr[i] += tree[i];
			
	}
	
	return flag;
}
