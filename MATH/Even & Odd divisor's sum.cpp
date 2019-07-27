/*
EVEN AND ODD DIVISORS
Vivek likes to solve mathematical problems. So, Dheer tries to challenge him with a problem. But Vivek is quite busy these days, So he asks for your help.

The problem is as follows: You are given an integer q which denotes the number of queries. For each query, You are given an integer n. You have to find the result of number n.

The result of a number n is defined as the sum of even divisors of n minus the sum of odd divisors of n.

More Formally, result = (Sum of even divisors of n) - (Sum of odd divisors of n)

A divisor of a number n is defined as a positive integer i such that n is divisible by i.

Input Format:
First line of input contains an integer q denoting the number of queries. After that q lines follow, Each line consists an integer n for which you have to find the value of result.

Note: Use fast input output as input is quite large;

Constraints:
1 <= q <= 100000 1 <= n <= 100000

Output Format
You have to print q lines, where the output of the ith line is the result of the ith query.

Sample Input
2
3
6
Sample Output
-4
4
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

int main()
{
    ll max = 100000;
    map<ll, pair<ll, ll>> fsum_to_num;

    fsum_to_num[0].first = fsum_to_num[0].second = 0;
    fsum_to_num[1].first = 0;
    fsum_to_num[1].second = 1;

    for (ll i = 2; i <= max; i++)
    {
        fsum_to_num[i].second += 1;
        (i & 1) ? fsum_to_num[i].second += i : fsum_to_num[i].first += i;

        for (ll j = 2 * i; j <= max; j += i)
        {
            (i & 1) ? fsum_to_num[j].second += i : fsum_to_num[j].first += i;
        }
    }

    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll num;
        cin >> num;
        cout << (fsum_to_num[num].first - fsum_to_num[num].second) << endl;
    }

    return 0;
}
