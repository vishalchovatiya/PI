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
ostream &operator<<(ostream &o, pair<T, T> &pair) // To print map in PRINT
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
using ll_pair = pair<ll, ll>;
using ull = unsigned long long;
using vll = vector<ll>;
using sll = set<ll>;
using msll = multiset<ll>;
using mll = map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

struct Query
{
    int L, R;
};

void queryResults(int a[], int n, Query q[], int m)
{
    ll block = (int)sqrt(n);

    sort(q, q + m, [&](Query &x, Query &y) {
        return (x.L / block < y.L / block) || (x.R < y.R);
    });

    int currL = 0, currR = 0;
    int currSum = 0;

    for (int i = 0; i < m; i++)
    {
        int L = q[i].L, R = q[i].R;

        while (currL < L)
        {
            currSum -= a[currL]; // remove
            currL++;
        }

        while (currL > L)
        {
            currSum += a[currL - 1]; // add
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR]; // add
            currR++;
        }

        while (currR > R + 1)
        {
            currSum -= a[currR - 1]; // remove
            currR--;
        }

        cout << "[" << L << ", " << R << "] = " << currSum << endl;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = {{1, 2}};
    int m = sizeof(q) / sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}
