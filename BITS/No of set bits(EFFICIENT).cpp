/*
  Find the no of set bits in given integer.
*/
#include <bits/stdc++.h>

#define DEBUG(X) std::cout << #X << " = " << X << std::endl;
#define PRINT(C, WAY)                      \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            WAY;                           \
        }                                  \
        cout << endl;                      \
    } while (0);
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define PRESENT(C, X) ((C).find() != (C).end())

using ll = long long;
using namespace std;

ll countSetBits(ll n)
{
    ll ans = 0;
    while (n)
    {
        n = n & (n - 1);
        ans++;
    }

    return ans;
}

int main()
{
    DEBUG(getSetBits(3));
    DEBUG(getSetBits(8));
    return 0;
}
