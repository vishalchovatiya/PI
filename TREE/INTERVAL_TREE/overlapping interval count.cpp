#include <bits/stdc++.h>

using namespace std;

#define DEBUG(X)    	std::cout<<#X<<" = "<<X<<std::endl;
#define PRINT(C,WAY)    do\
                        {\
                            cout<<setw(10)<<#C<<" : ";\
                            for(auto&& i : C) {\
                                WAY;\
                            }\
                            cout<<endl;\
                        } while (0);

class intervalTree{

	using intPair = pair<int,int>;

	struct node
	{
		intPair 	m_p;
		int 		m_max = 0;
		node* 		m_left = NULL;	
		node* 		m_right = NULL;
		
		node(intPair p):m_p(p),m_max(max(p.first, p.second)){}
	};

	node* m_root = NULL;

public:
	void insert(intPair range){
		node* curr = m_root;
		node* prev = m_root;

		while(curr != NULL){
			prev = curr;
			curr->m_max = max(curr->m_max, range.second);

			// DEBUG(curr->m_p.first);

			if(range.first < curr->m_p.first){
				// DEBUG("LEFT");
				curr = curr->m_left;
			}
			else{
				// DEBUG("RIGHT");
				curr = curr->m_right;
			}
		}

		if(prev==NULL) {
			m_root = new node(range);
		}
		else if(range.first < prev->m_p.first){
			prev->m_left = new node(range);
		}
		else{
			prev->m_right = new node(range);
		}

	}

	void print(){
		print(m_root);
		cout<<endl;
	}

	void print(node* root){
		if(root==NULL)return;

		print(root->m_left);
		cout<<"("<<root->m_p.first<<","<<root->m_p.second<<") = "<<root->m_max<<", ";
		print(root->m_right);
	}

	int ovrlpIntrvlCnt(intPair range) {
		int count=0;

		node* curr = m_root;

		while(curr != NULL){
	
			// DEBUG(curr->m_p.first);
			// DEBUG(curr->m_p.second);

			// DEBUG((curr->m_p.first >= range.first && curr->m_p.first <= range.second));
			// DEBUG((curr->m_p.second >= range.first && curr->m_p.second <= range.second));

			if((curr->m_p.first >= range.first && curr->m_p.first <= range.second)
				|| (curr->m_p.second >= range.first && curr->m_p.second <= range.second)){
				count++;
			}
			// else break;

			// if(range.first < curr->m_p.first){
			if (curr->m_left != NULL && curr->m_left->m_max >= curr->m_p.first){
				// DEBUG("LEFT");
				curr = curr->m_left;
			}
			else{
				// DEBUG("RIGHT");
				curr = curr->m_right;
			}

			// DEBUG("====================");
		}

		return count;
	}
};

int main(){
	intervalTree iT;
#if 01	
	iT.insert(make_pair(15,20));
	iT.insert(make_pair(10,30));
	iT.insert(make_pair(17,19));
	
	iT.insert(make_pair(5,20));
	iT.insert(make_pair(12,15));
	
	iT.insert(make_pair(30,40));

	DEBUG(iT.ovrlpIntrvlCnt(make_pair(15,25)));
#else
	iT.insert(make_pair(1,2));
	iT.insert(make_pair(2,3));
	iT.insert(make_pair(4,5));
	iT.insert(make_pair(6,7));
	DEBUG(iT.ovrlpIntrvlCnt(make_pair(1,5)));
	DEBUG(iT.ovrlpIntrvlCnt(make_pair(2,3)));
	DEBUG(iT.ovrlpIntrvlCnt(make_pair(4,7)));
	DEBUG(iT.ovrlpIntrvlCnt(make_pair(5,7)));
#endif	
	iT.print();
	return 0;
}
