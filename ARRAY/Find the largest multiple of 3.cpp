#include <iostream>

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
	Question:- Find the largest multiple of 3
	
	Input: arr[] = {8, 1, 9}
	Output: 981
	
	Input: arr[] = {8, 1, 7, 6, 0}
	Output: 8760

	Solution:- 
	
	Method 1 (Brute Force) : Time Complexity: O(n x 2^n). There will be 2^n combinations of array elements. To compare each combination with the largest number so far may take O(n) time.
	
	Method 2 
	
	1) Sort in increasing order
	2) Check for largest sum divided by 3 & elements which form largest sum
	3) Print elements in decreasing order & is answer
	
	Trick: A number is multiple of 3 if and only if the sum of digits of number is multiple of 3. For example, let us consider 8760, it is a multiple of 3 because sum of digits is 8 + 7+ 6+ 0 = 21, which is a multiple of 3. 
*/

bool compare (int i,int j) { return (i>j); }

void LargestMultipleOf3(int arr[], int size){
	
	vector<int> V(arr, arr+size);
	
	sort( V.begin(), V.end());
	
	int sum = accumulate(V.begin(), V.end(), 0);
	
	if( sum % 3 == 0);
	else
		for(int i=0; i<V.size(); i++){
			if ( (sum - V[i] ) % 3 == 0 ){
				sum = sum - V[i];
				V.erase(find(V.begin(), V.end(), V[i]));
				break;
			}
				
		}
	
	sort( V.begin(), V.end(), compare);
	
	for(vector<int> ::iterator i=V.begin(); i!=V.end() ;i++ ){
		cout<<(*i);
	}
}

int main() {
	int arr[] = {8, 1, 9};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	LargestMultipleOf3(arr, size);

	return 0;
}
