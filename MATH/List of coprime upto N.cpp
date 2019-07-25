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
    o << pair.first << " " << pair.second << endl;
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

vector<ll> smallest_prime_factor;
ll primes_upto = 500;

/*
index: 0  | 1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15
prime: -1 | -1 | 2 | 3 | 2 | 5 | 2 | 7 | 2 | 3 | 2  | 11 | 2  | 13 | 2  | 3
Note: Could multiple as well
 */
template <typename T>
vector<T> precomp_small_primes_upto(T n)
{
    vector<T> prime_list((n + 1), numeric_limits<T>::max());

    for (T d = 2; d <= n; d++)
    {
        prime_list[d] = min(d, prime_list[d]); // self divisible

        for (T i = (d * d); i <= n; i += d)
        {
            prime_list[i] = min(d, prime_list[i]);
        }
    }

    return prime_list;
}

template <typename T>
map<T, T> smallest_prime_factors_of(T n)
{
    map<T, T> prime_factors;

    while (n > 1)
    {
        prime_factors[smallest_prime_factor[n]]++;
        n /= smallest_prime_factor[n];
    }

    return prime_factors;
}

int main()
{
    ll N = 4;

    // read(N);

    smallest_prime_factor = precomp_small_primes_upto(primes_upto);

    map<ll, ll> factors;

    for (ll num = N; num > 1; --num)
    {
        // DEBUG(num);
        map<ll, ll> factors_num = smallest_prime_factors_of(num);

        // PRINT(factors_num);

        for (auto &&fctr : factors_num)
        {
            factors[fctr.first] += fctr.second;
        }
        // DEBUG("=============")
    }

    PRINT(factors);

    // for (auto &&fctr : factors)
    // {
    // }

    return 0;
}
