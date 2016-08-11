#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as 
{4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is 2nd petrol pump. 
Output should be “start = 1″ (index of 2nd petrol pump).

A Simple Solution is to consider every petrol pumps as starting point and see if there is a possible tour. 
If we find a starting point with feasible solution, we return that starting point. 
The worst case time complexity of this solution is O(n^2).

We can use a Queue to store the current tour. We first enqueue first petrol pump to the queue, 
we keep enqueueing petrol pumps till we either complete the tour, or current amount of petrol becomes negative. 
If the amount becomes negative, then we keep dequeueing petrol pumps till the current amount becomes positive or queue becomes empty.
*/

class	cirTour{
	public:
	int ptrl;
	int dist;
	cirTour(int ptrl, int dist){
		this->ptrl = ptrl;
		this->dist = dist;
	}
	
	int getCurrPtrlStatus(){
		return this->ptrl - this->dist;
	}
};

int cirTourStartPoint(cirTour cT[], int noOfPump){
	int currPtrl = cT[0].getCurrPtrlStatus();
	queue<cirTour>	Q;
	int i=1;
	Q.push(cT[0]);
	
	while( !Q.empty() && (Q.size() != noOfPump || currPtrl < 0) ){
		
		while( !Q.empty() && currPtrl < 0 ){
			currPtrl -= Q.front().getCurrPtrlStatus();
			Q.pop();
		}
		Q.push(cT[i]);
		currPtrl += cT[i].getCurrPtrlStatus();
		i = ++i % noOfPump;
	}

	return i;
}

int main() {
    cirTour cT[4] = {{4, 6}, {6, 5}, {7, 3} , {4, 5}};
    
    cout<<cirTourStartPoint( cT, 4)<<endl;
    
    return 0;
}
