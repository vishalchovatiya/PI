#include <iostream>
#include <queue>
#include <string>
using namespace std;

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
