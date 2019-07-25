/*https://www.hackerearth.com/problem/algorithm/magic-fractions/
Alice is fond of playing mathematical games. This time he comes up with a unique game. He takes a number 'N' and calls magic fraction of N as:

It is a proper fraction (The value is < 1)
It cannot be reduced further
The product of the numerator and the denominator is factorial of N. i.e. if a/b is the fraction, then a*b = N! 
For example magic fractions for 3 are 2/3 and 1/6. 

Now given a number N, you need to print the total number of magic fractions that exist, for all numbers from 1 till N (both inclusive).
Input Format:
Single line containing integral value 'N'.

Constraints:
1<=N<=500

Output Format
Print integral value denoting total number of magic fractions.

Sample Input
3
Sample Output
3
*/

/* Algo
https://codereview.stackexchange.com/questions/60846/magic-fraction-finder
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

template <typename T>
T binary_exponentiation(T x, T n, T m = numeric_limits<T>::max()) // x^n in log(N) time
{
    T res = 1;
    while (n > 0)
    {
        if (n & 0x1)
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n = n / 2;
    }

    return res;
}

int main()
{
    ll ans = 0;
    ll N;

    read(N);

    smallest_prime_factor = precomp_small_primes_upto(primes_upto);
    map<ll, ll> factors;

    for (ll num = 1; num <= N; num++)
    {
        map<ll, ll> factors_num = smallest_prime_factors_of(num);

        for (auto &&fctr : factors_num)
        {
            factors[fctr.first] += fctr.second;
        }

        ans += binary_exponentiation((ll)2, (ll)factors.size()) / 2;
    }

    cout << ans << endl;

    return 0;
}
