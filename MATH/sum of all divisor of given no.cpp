/*
input:
8 <--- Query
10
30
45
9
69
77
127
150

Output:
8
42
33
4
27
19
1
222
*/

#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
int main(){
        vector<ll> v(1000000,1);
        ll i,j;
        for(i=2;i<=1000000;i++){
                for(j=2*i;j<=1000000;j+=i)
                        v[j] += i;
        }
        cin>>i;
        while(i--){
                cin>>j;
                cout<<v[j]<<endl;
        }
        return 0;
}
