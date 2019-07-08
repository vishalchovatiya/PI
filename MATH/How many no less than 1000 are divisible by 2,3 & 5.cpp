
// All the no that are less than 1000 & divisible by 2,3 & 5
// inclusion-exclusion principle

#include <bits/stdc++.h>

#define DEBUG(X) cout << #X << " = " << X << endl;
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

inline bool isOdd(ll num)
{
    return num & 0x1;
}

vector<ll> nextSubset(ll n, unordered_map<ll, ll> &mapping)
{
    vector<ll> subset;
    ll idx = 0;
    while (n)
    {
        if (n & 1)
            subset.push_back(mapping[idx]);

        idx++;
        n = n >> 1;
    }
    return subset;
}

vector<vector<ll>> getAllSubset(ll arr[], ll size)
{
    vector<vector<ll>> subsets;
    ll end = (1 << size) - 1; // max possble subset would be 2^n - 1

    // map element to bit mask idx
    unordered_map<ll, ll> mapping;
    for (ll charIdx = 0; charIdx < size; charIdx++)
        mapping[charIdx] = arr[charIdx];

    // generate all subset
    for (ll num = 1; num <= end; num++)
    {
        subsets.push_back(nextSubset(num, mapping));
    }
    return subsets;
}

ll totalNoDivisibleBySubset(ll num, vector<vector<ll>> &subsets)
{
    ll ans = 0;

    // inclusion-exclusion principle
    for (auto &&v : subsets)
    {
        ll divisor = accumulate(ALL(v), 1, multiplies<ll>());

        ll totalNum = num / divisor;

        if (isOdd(v.size()))
        {
            ans += totalNum;
        }
        else
            ans -= totalNum;
    }

    return ans;
}

int main()
{
    ll arr[] = {2, 3, 5};

    vector<vector<ll>> subsets = getAllSubset(arr, 3);

    cout << totalNoDivisibleBySubset(1000, subsets);

    return 0;
}
