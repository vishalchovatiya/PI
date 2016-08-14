#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <string>
using namespace std;

/*
	Question: 
	- Suppose we have a paging system with 4 frames and 12 pages, where the number of frames denotes the number of pages that can be held in RAM at any given time. 
	- Assume the pages are accessed by some program in the order shown below, from left to right. 
	- Also, assume that the program has just started, so the frames are initially empty. 
	- Design Caching system which generate minimum page faults
 
	Order in which pages are accessed: 	3, 4, 2, 1, 4, 7, 2, 5, 3, 6, 1, 3
*/

class LRUCache{
	size_t Capacity;
	
	map< size_t, list<int> :: iterator>		Table;		// Availibility Table
	list<int>								Cache;		// Container

	public:
		void adjustContainerCapacity(){
			while( Cache.size() > Capacity )
				Cache.pop_back();
		}
		
		void printContainer(){
			for_each(Cache.begin(), Cache.end(), [](const int x){cout<<" "<<x;});
			cout<<endl;
		}
		
		LRUCache(size_t Capacity){
			this->Capacity = Capacity;
		}
		
		void referencePage(size_t Key){			
			map< size_t, list<int> :: iterator> :: iterator it = Table.find(Key);
			
			if( it != Table.end() ){	// If Key Exist in Cache, 			
				Cache.erase( (*it).second );
				Cache.push_front(Key);
			}else{						// If not exist in Cache,			
				cout<<"Page Fault Occur Key = "<<Key<<endl;	
				Table[Key] = getPage( Key);			// get New Page
			}			
			adjustContainerCapacity();
			printContainer();
		}
		
		list<int> :: iterator getPage(size_t Key){				
			Cache.push_front(Key);			
			return Cache.begin();
		}
		
};

int main(){

	LRUCache LRU(4);
	
	LRU.referencePage(3);
	LRU.referencePage(4);
	LRU.referencePage(2);
	LRU.referencePage(1);
	
	LRU.referencePage(7);
	LRU.referencePage(5);
	LRU.referencePage(5);
	LRU.referencePage(5);
	LRU.referencePage(6);

	return 0;
}
