
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

#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld", &n)

#define matrix vector<vector<ll>>

matrix mul(matrix &A, matrix B)
{
    matrix C(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int x = 0; x < 2; x++)
                C[i][j] = (C[i][j] + A[i][x] * B[x][j]) % MOD;
        }
    }
    return C;
}

matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p & 1)
        return mul(A, pow(A, p - 1));
    matrix X = pow(A, p / 2);
    return mul(X, X);
}

ll fib(ll n)
{
    if (!n)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    vector<ll> F1(2);
    F1[0] = F1[1] = 1;
    matrix T(2, vector<ll>(2));
    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;
    T = pow(T, n - 1);
    ll res = 0;
    for (int i = 0; i < 2; i++)
    {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res % MOD;
}
int main()
{
    DEBUG(fib(47));
    return 0;
}
