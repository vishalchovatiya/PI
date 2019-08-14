/*
ALPHA SCORE
You are climbing up using stairs where a number is written on each stair. At each step we define the alpha score as sum of all the numbers previously seen on the stairs which are smaller than the present number. Alpha score of the whole journey is defined as the sum of all the alpha scores at each step. Print the alpha score of whole journey modulus 1000000007.

Input Format:
First line contains a single integer n denoting the number of stairs. Next line contains n space separated integers denoting the numbers written on stairs.

Constraints:
1 <= n <= 10^5 Every number written on stair lies between [0,10^9]

Output Format
Single integer denoting the alpha score of the journey modulus 1000000007.

Sample Input
5
1 5 3 6 4
Sample Output
15


Sample Input
5
5 5 5 5 6
Sample Output
20
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

ll mod = 1000000007;
int main()
{
    map<ll, ll> bst;

    ll N;
    cin >> N;

    ll sum = 0;
    for (ll i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;

        sum = accumulate(begin(bst), bst.lower_bound(temp), sum, [](ll &sum, auto &pair) {
                  return sum + pair.second;
              }) %
              mod;

        bst[temp] += temp;
    }

    cout << sum << endl;

    return 0;
}
