#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

/*
	Q: Find the largest subarray with 0 sum
	
	Input: {4, 2, -3, 1, 6}
	Output: true 
	There is a subarray with zero sum from index 1 to 3.
	
	Input: {4, 2, 0, 1, 6}
	Output: true 
	There is a subarray with zero sum from index 2 to 2.
	
	Input: {-3, 2, 3, 1, 6}
	Output: false
	There is no subarray with zero sum.
	
	Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	Output: 5
	The largest subarray with 0 sum is -2, 2, -8, 1, 7
	
	Input: arr[] = {1, 2, 3}
	Output: 0
	There is no subarray with 0 sum
	
	Input: arr[] = {1, 0, 3}
	Output: 1

*/

void subArrayWithSumZero(int arr[], int size){
	
	int sum = 0;
	int maxLen =0;
	map<int,int>	Table;
	list<pair<int,int>>	Result;

	for(int i=0;i<size;i++){
		sum = sum + arr[i];
		
		if( arr[i] == 0 && maxLen )
			maxLen++;
		
		if(sum==0)
			maxLen = i+1;
		
		if( Table.find(sum) != Table.end() ){
			maxLen = max( maxLen, i-Table[sum]);
			Result.push_back(make_pair( Table[sum]+1, i-Table[sum]));
		}
		else{
			Table[sum] = i;
		}
	}
	
	for(list<pair<int,int>> ::iterator it=Result.begin();it!=Result.end();it++){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    subArrayWithSumZero(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
