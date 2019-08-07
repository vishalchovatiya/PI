/*
N-QUEEN HARD
You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format:
A single integer N, denoting the size of chess board.

Constraints:
1 ≤ N < 15

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2
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
using ull = unsigned long long;
using vll = vector<ll>;
using sll = set<ll>;
using msll = multiset<ll>;
using mll = map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

ll mask = 0;
ll ans = 0;

inline ll get_lsb_set_bit(ll n)
{
    return n & (-n);
}

void no_of_ways(const ll &N, ll r = 0, ll col = 0, ll ld = 0, ll rd = 0)
{
    if (r == N)
    {
        ans++;
        return;
    }

    ll safe = (mask & (~(col | ld | rd)));

    while (safe)
    {
        ll place = get_lsb_set_bit(safe);
        safe = safe - place;
        no_of_ways(N, r + 1, col | place, (ld << 1) | (place << 1), (rd >> 1) | (place >> 1));
    }
}

int main()
{
    ll n;
    cin >> n;

    mask = ~((-1) << n);

    no_of_ways(n);
    cout << ans << endl;

    return 0;
}
