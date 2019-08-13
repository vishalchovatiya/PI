/*
AGGRESSIVE COWS
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format:
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Constraints:
Output Format
Print one integer: the largest minimum distance.

Sample Input
5 3
1 2 8 4 9
Sample Output
3

*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <memory>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

/* ------------------------- HELPERS DEFINE -------------------------- */
template <typename T>
ostream &operator<<(ostream &o, pair<const T, T> &pair) // To print map in PRINT
{
    o << pair.first << " -> " << pair.second << endl;
    return o;
}
#define SIZE_OF(ARR) (sizeof(ARR) / sizeof(ARR[0]))
template <typename... T>
void read(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T... args)
{
    ((cout << args), ...);
}

#define DEBUG(X) cout << #X << " = " << X << endl;
#define PRINT(C)                           \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            cout << i << " ";              \
        }                                  \
        cout << endl;                      \
    } while (0);

#define ALL(C) (C).begin(), (C).end()
#define PRESENT(C, X) ((C).find(X) != (C).end())
#define BENCHMARK(f)         \
    do                       \
    {                        \
        cout << #f << " = "; \
        benchmark(f);        \
    } while (0);

const auto benchmark = [](function<void(void)> f) {
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    f();
    cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << " microseconds\n";
};

using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using sll = set<ll>;
using msll = multiset<ll>;
using mll = map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

bool validate(sll &arr, ll size, ll d, ll cows)
{
    auto it = arr.begin();

    ll pos = *it++;
    cows--;

    for (; it != arr.end(); it++)
    {
        if ((pos + d) < (*it))
        {
            pos = (*it);
            cows--;
        }
        if (cows == 0)
        {
            return true;
        }
    }

    return false;
}

ll search(sll &arr, ll size, ll s, ll e, ll cows)
{
    ll mid = -1;
    while (s < e)
    {
        mid = (s + e) / 2;

        if (!validate(arr, size, mid, cows))
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return mid;
}

int main()
{
    ll Q = 1;
    // cin >> Q;
    while (Q--)
    {
        ll N, M;
        cin >> N;
        cin >> M;
        sll arr;

        ll min_val = numeric_limits<ll>::max(), max_val = numeric_limits<ll>::min();
        for (ll i = 0; i < N; i++)
        {
            ll temp;
            cin >> temp;
            arr.insert(temp);

            min_val = min(min_val, temp);
            max_val = max(max_val, temp);
        }

        // PRINT(arr);
        // DEBUG(min_val)
        // DEBUG(max_val)
        cout << search(arr, N, min_val, max_val, M);
    }

    return 0;
}
