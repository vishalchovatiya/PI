/*
PAINTER'S PARTITION PROBLEM
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.

Input Format:
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints:
1 <= K <= 10
1 <= N <= 10
1<= Length Of Each Board <= 10^8

Output Format:
Output the minimum time required to paint the board.

Sample Input:
2
2
1 10
Sample Output:
10
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

bool validate(vll &arr, ll mid, const ll painters)
{
    ll sum = 0;
    ll p = 1;

    for (auto &&board_sz : arr)
    {
        // cout << board_sz << " ";
        if ((sum + board_sz) > mid)
        {
            sum = board_sz;
            p++;
            if (p > painters)
                return false;
        }
        else
        {
            sum += board_sz;
        }
    }
    // cout << endl;
    // DEBUG(p)

    return true;
    // return ((p + 1) == painters);
}

ll search(vll &arr, ll s, ll e, const ll painters)
{
    bool last = true;
    ll mid = -1;
    // DEBUG("__________________________")
    while (s <= e)
    {
        mid = (s + e) / 2;
        // DEBUG(mid)

        if (validate(arr, mid, painters))
        {
            // DEBUG("LEFT")
            last = true;
            e = mid - 1;
        }
        else
        {
            // DEBUG("RIGHT")
            last = false;
            s = mid + 1;
        }
        // DEBUG("=============")
        // break;
    }

    return (last == false) ? mid + 1 : mid;
}

int main()
{
    ll Q = 1;
    // cin >> Q;
    while (Q--)
    {
        ll boards, painters;
        cin >> painters;
        cin >> boards;
        vll arr(boards);

        ll min_val = numeric_limits<ll>::min(), max_val = 0;
        for (ll i = 0; i < boards; i++)
        {
            ll temp;
            cin >> temp;
            arr[i] = (temp);

            min_val = max(min_val, temp);
            max_val += temp;
        }

        // PRINT(arr)
        // DEBUG(min_val)
        // DEBUG(max_val)
        cout << search(arr, min_val, max_val, painters);
    }

    return 0;
}
