#include <iostream>
#include <string.h>
#include <map>
#include <list>
using namespace std;

/*
	Q: Check if an array can be divided into pairs whose sum is divisible by k
	
	Input: arr[] = {9, 7, 5, 3}, k = 6
	Output: True
	We can divide array into (9, 3) and (7, 5).
	Sum of both of these pairs is a multiple of 6.
	
	Input: arr[] = {92, 75, 65, 48, 45, 35}, k = 10
	Output: True
	We can divide array into (92, 48), (75, 65) and 
	(45, 35). Sum of all these pairs is a multiple of 10.
	
	Input: arr[] = {91, 74, 66, 48}, k = 10
	Output: False
*/

bool divideInPairsSumDivisibleByK( int arr[], int size, int k){
	
		int tempArr[100] = {0};
	
	memcpy( tempArr, arr, sizeof(tempArr));
	
	for(int i=0; i<size; i++){
		tempArr[i] = arr[i] % k;
	}
	
	map<int,int>	Table;
	list<pair<int,int>>		Result;
	int pair = 0;
	
	for(int i=0; i<size; i++){
		if( Table.find(tempArr[i]) != Table.end() ){
			pair++;
			Result.push_back( make_pair( arr[i], arr[Table[tempArr[i]]]));
		}
		else
			Table[k-tempArr[i]] = i;
	}

	for( std::list<std::pair<int, int> > :: iterator i = Result.begin(); i!=Result.end(); i++ ){
		cout<<(*i).first<<" "<<(*i).second<<endl;
	}

	if( pair*2 < size )
		return false;
	
	return true;
}

int main() {
    int arr[] = {92, 75, 65, 48, 45, 35};
    int k = 10;
    
    cout<<divideInPairsSumDivisibleByK(arr,sizeof(arr)/sizeof(arr[0]),k)<<endl;
    return 0;
}
