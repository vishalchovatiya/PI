/*
- Divide nodes in two parts & set it to left & right child repeat this process till single node
- elements are always in leaf nodes

Condition to build, query & update segment tree-------MOST IMP

1. No overlap
qs___qe                  qs____qe
        s_____________e

2. Complete overlap
      qs_____________qe
            s___e

3. Partial overlap
            s___e
      qs_____________qe
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
    return root * 2;
}

inline ll RIGHT(ll root)
{
    return root * 2 + 1;
}

void build_segment_tree(ll arr[], ll seg[], ll s, ll e, ll index)
{
    if (s == e)
    {
        seg[index] = arr[s];
        return;
    }

    ll mid = (s + e) / 2;

    build_segment_tree(arr, seg, s, mid, LEFT(index));
    build_segment_tree(arr, seg, mid + 1, e, RIGHT(index));

    seg[index] = min(seg[LEFT(index)], seg[RIGHT(index)]);
}

ll range_query(ll arr[], ll seg[], ll s, ll e, ll l, ll r, ll index)
{
    // No overlap
    if (r < s || l > e)
    {
        return 0xFFFFFF;
    }

    // Complete overlap
    if (l <= s && r >= e)
    {
        return seg[index];
    }

    // Partial overlap
    ll mid = (s + e) / 2;

    ll l_min = range_query(arr, seg, s, mid, l, r, LEFT(index));
    ll r_min = range_query(arr, seg, mid + 1, e, l, r, RIGHT(index));

    return min(l_min, r_min);
}

void update(ll arr[], ll seg[], ll s, ll e, ll i, ll val, ll index)
{
    // Not lie in the range
    if (i < s || i > e)
    {
        return;
    }

    // Got leaf with same i
    if (i == s && i == e)
    {
        seg[index] = val;
        DEBUG(seg[index])
        return;
    }

    // Partial overlap
    ll mid = (s + e) / 2;

    update(arr, seg, s, mid, i, val, LEFT(index));
    update(arr, seg, mid + 1, e, i, val, RIGHT(index));

    seg[index] = min(seg[LEFT(index)], seg[RIGHT(index)]);
}

int main()
{
    ll arr[] = {4, 1, 3, 7, 2};

    ll seg[SIZE_OF(arr) * 4 + 1] = {0};

    build_segment_tree(arr, seg, 0, SIZE_OF(arr) - 1, 1);

    DEBUG(range_query(arr, seg, 0, SIZE_OF(arr) - 1, 1, 3, 1));

    PRINT(seg)

    update(arr, seg, 0, SIZE_OF(arr) - 1, 1, -1, 1);

    // PRINT(arr)
    PRINT(seg)

    return 0;
}
