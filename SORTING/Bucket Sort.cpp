#include <iostream>
#include <algorithm>
#include <list>
#include <climits>
#include <math.h>  
using namespace std;

/*
	Worst Case Time Complexity is O(NxN)
	
	divider = ceil( (Max+1) / noOfBucket )
	
	choosedBucket = floor( arr[i] / divider )
	
*/

void sortedInsert(list<int>	&bucket, int element){
	
	if( bucket.empty() ){
		bucket.push_back(element);
		return;
	}	
	
	list<int> :: iterator i;
	for( i=bucket.begin(); i!=bucket.end(); i++){
		if( (*i) >= element ){
			break;
		}
	}
	
	bucket.insert(i, element);
}

void printBucket(list<int>	*buckList, int noOfBucket){
	for(int i=0; i<noOfBucket; i++){		
		for_each( buckList[i].begin(),  buckList[i].end(), [](const int i){cout<<i<<" ";});
		cout<<endl;
	}
}

void bucketSort(int arr[], int size){
	
	int noOfBucket = size / 2;
	int Max = INT_MIN;
	
	for(int i=0; i<size; i++)
		Max = max(Max,arr[i]);
	
	int divider = ceil( (Max+1) / noOfBucket );
	
	list<int>	*buckList = new list<int>[divider];
		
	for(int i=0; i<size; i++){		
		int choosedBucket = floor( arr[i] / divider );		
		sortedInsert( buckList[choosedBucket], arr[i]);
	}
	
	int j=0;
	for(int i=0; i<noOfBucket; i++){		
		for( list<int> :: iterator it=buckList[i].begin(); it!=buckList[i].end(); it++){
			arr[j++] = *it;
		}
	}
}

int main() {
    int A[] = { 3, 7, 1, 9 };
    int size = sizeof(A)/sizeof(A[0]);
    
    bucketSort(A,size);
    
    for_each(A,A+size,[](const int i){cout<<i<<" ";});
}
