/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.
Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.
Constraints:
1<=t<=100
1<=n<=90
Output Format:
Print the number of all possible binary strings.
Sample Input:
2
2
3
Sample Output:
3
5
Explanation:
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
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
using namespace std;

/* --------------------------------------------------------------------- */
ll arr[100] = {0};

ll no_of_ways(ll n, ll curr = 0)
{
    if (n == 0)
    {
        return 1;
    }

    if (arr[n] != 0 && curr == 0)
        return arr[n];

    ll res = no_of_ways(n - 1, 0);

    if (curr != 1)
        res += no_of_ways(n - 1, 1);

    if (arr[n] == 0)
        arr[n] = res;

    return res;
}

int main()
{

    no_of_ways(90);

    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll temp;
        cin >> temp;
        cout << arr[temp] << endl;
        // cout << no_of_ways(temp) << endl;
    }

    return 0;
}
