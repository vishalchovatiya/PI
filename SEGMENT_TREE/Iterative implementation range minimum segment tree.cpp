/*
Build:
- Element at index i in original array will be at index (i + N) in the segment tree array.
- Now to calculate the parents, we will start from index (N – 1) and move upward

Query:
- If l in query is right child consider only seg[l] node, discard left subtree completely
-
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
// using msll = multiset<ll>;
using mll = map<ll, ll>;
// using mmll = multimap<ll, ll>;
using namespace std;

inline ll LEFT(ll root)
{
    return (root << 1);
}

inline ll RIGHT(ll root)
{
    return (root << 1) | 1;
}

inline ll PARENT(ll child)
{
    return (child >> 1);
}

inline ll SIBLING(ll child)
{
    return (child ^ 1);
}

void build_segment_tree(ll arr[], ll N, ll seg[])
{
    for (ll idx = 0; idx < N; idx++)
        seg[idx + N] = arr[idx];

    for (ll idx = N - 1; idx > 0; --idx)
        seg[idx] = min(seg[LEFT(idx)], seg[RIGHT(idx)]);
}

ll query(ll seg[], ll N, ll l, ll r)
{
    ll res = seg[r + N];

    for (l += N, r += N; l != r; l = PARENT(l), r = PARENT(r))
    {
        if (l & 1) // is right child
            res = min(res, seg[l++]);

        // if (r & 1) // is right child
        // res = min(res, seg[r--]);
    }

    return min(res, seg[l]);
}

void update(ll seg[], ll N, ll i, ll val)
{
    i = i + N;
    seg[i] = val;

    for (ll idx = i; idx > 1; idx = PARENT(idx))
        seg[PARENT(idx)] = min(seg[idx], seg[SIBLING(idx)]);
}

int main()
{
    // ll arr[] = {1, 8, 3, 7};
    ll arr[] = {8, 1, 7, 3};

    ll seg[SIZE_OF(arr) * 2] = {0};

    build_segment_tree(arr, SIZE_OF(arr), seg);

    PRINT(arr)
    PRINT(seg)

    // update(seg, SIZE_OF(arr), 10, -5);
    // PRINT(seg)

    // DEBUG(query(seg, SIZE_OF(arr), 0, 1));
    // DEBUG(query(seg, SIZE_OF(arr), 0, 2));
    DEBUG(query(seg, SIZE_OF(arr), 0, 3));
    // DEBUG(query(seg, SIZE_OF(arr), 2, 3));
    // DEBUG(query(seg, SIZE_OF(arr), 3, 3));
    // DEBUG(query(seg, SIZE_OF(arr), 0, 3));
    // DEBUG(query(seg, SIZE_OF(arr), 0, 0));
    // DEBUG(query(seg, SIZE_OF(arr), 1, 1));

    return 0;
}
