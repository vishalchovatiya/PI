#include <bits/stdc++.h>
using namespace std;

#define DEBUG(X)	std::cout<<__FILE__":"<<__LINE__<<":"<<#X<<" = "<<X<<std::endl

template<
typename Key,
typename Priority,
typename Compartor = std::less<Priority>
>
class PriorityQueue{
	Compartor										m_Comp;
	std::vector<std::pair<Key, Priority> >        	m_Heap;
	std::map<Key, uint32_t>             			m_KeyPosMap;

    private:  /*--------------------------------Debugging methods -----------------------------------*/

	void displayHeap() const
	{
		for(auto&& i : m_Heap)
		{
			std::cout<<" "<<(i).first<<" "<<(i).second<<endl;
		}
		cout<<endl;
	}

	void DisplayIndexMapped()
	{
		for(auto&& i : m_KeyPosMap) 
		{
			cout<<"  "<<i.first<<"  "<<i.second<<endl;
		}
		cout<<endl;
	}

    private:  /*--------------------------------Utility methods -----------------------------------*/

	inline int RIGHT(int X)const{
		return (X*2+2);	
	}
	inline int LEFT(int X)const{
		return (2*X+1);
	}
	inline int PARENT(int X)const{
		return ((X-1)/2);
	}

	void HeapifyUP( int idx){
		int P = PARENT(idx);

		if( P >= 0 && m_Comp(m_Heap[idx].second, m_Heap[P].second))
		// if( P >= 0 && m_Heap[idx].second < m_Heap[P].second)
		{
          // Update position in map
			m_KeyPosMap[m_Heap[P].first] = idx;
			m_KeyPosMap[m_Heap[idx].first] = P;

          // Swap position in heap
			swap( m_Heap[idx], m_Heap[P]);

          // Repeat same
			HeapifyUP( P);
		}	
	}

	void HeapifyDOWN( int idx){			
		int R = RIGHT(idx), min = LEFT(idx);

		if( min <= m_Heap.size() && R <= m_Heap.size() && m_Comp(m_Heap[R].second, m_Heap[min].second))	{
			min = R;
		}

		if( min <= m_Heap.size() && m_Comp(m_Heap[min].second, m_Heap[idx].second))	{
          // Update position in map
			m_KeyPosMap[m_Heap[min].first] = idx;
			m_KeyPosMap[m_Heap[idx].first] = min;

          // Swap position in heap
			swap( m_Heap[idx], m_Heap[min]);

          // Repeat same
			HeapifyDOWN( min);
		}
	}

    public:/*------------------------------------ Main Interfaces ------------------------------------*/

	void push(std::pair<Key, Priority> val){    
		m_KeyPosMap[val.first] = m_Heap.size();
		m_Heap.push_back(val);
		HeapifyUP( m_Heap.size()-1);
	}

	std::pair<Key,Priority> top() const{    
		return m_Heap.front();
	}

	void pop(){    
		std::pair<Key,Priority> retVal = m_Heap.front();
		m_KeyPosMap.erase( retVal.first);

		m_Heap[0] = m_Heap[ m_Heap.size() - 1 ];
		m_Heap.pop_back();

		m_KeyPosMap[m_Heap[0].first] = 0;
		HeapifyDOWN( 0);
	}

	void update(std::pair<Key,Priority> newVal){
		if( m_Comp(newVal.second, m_Heap[ m_KeyPosMap[newVal.first] ].second) )
		{
			m_Heap[ m_KeyPosMap[newVal.first] ].second = newVal.second;
			HeapifyUP( m_KeyPosMap[newVal.first]);
		}
		else
		{
			m_Heap[ m_KeyPosMap[newVal.first] ].second = newVal.second;
			HeapifyDOWN( m_KeyPosMap[newVal.first]);
		}
	}

	void remove(std::pair<Key,Priority> remVal){
		update(make_pair(remVal.first, INT_MIN));
		pop();
	}

	inline uint32_t size() const{
		return m_Heap.size();
	}

	inline bool empty() const{
		return !m_Heap.size();
	}

	inline bool isContain(Key k) const {
		return !(m_KeyPosMap.find(k) == m_KeyPosMap.end());
	}

	std::pair<Key,Priority> getPriority(Key k){
		return (isContain(k)) ? m_Heap[m_KeyPosMap[k]] : std::pair<Key,Priority>();
	}
};

int main() {
	PriorityQueue<int, int, std::greater<int>> pq;
	pq.push(make_pair(1,1));
	pq.push(make_pair(2,2));
	pq.push(make_pair(3,3));

	pq.update(make_pair(3,0));

	// if(pq.isContain(make_pair(3,0))) DEBUG(1);

	while(!pq.empty()){
		std::pair<int,int> val = pq.top();
		pq.pop();
		DEBUG(val.first);
		DEBUG(val.second);
	}
  ///////////////////////////////////////////////  Example 2

	struct Key{
		int m_u;
		int m_v;

		Key(int u, int v):m_u(u), m_v(v){}

		bool operator <(const Key& rhs) const
		{
			return m_u < rhs.m_u;
		}
	};


	PriorityQueue<Key, int> pq2;

	pq2.push(std::make_pair(Key(0,1), 2));
	pq2.push(std::make_pair(Key(0,2), 3));
	pq2.push(std::make_pair(Key(0,3), 4));

	while(!pq2.empty()){
		std::pair<Key, int> temp = pq2.top();
		pq2.pop();

		cout<<temp.first.m_u<<" "<<temp.first.m_v<<" -> "<<temp.second<<"\n";
	}
}
