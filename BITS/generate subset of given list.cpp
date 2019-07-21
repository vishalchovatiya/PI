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
#define PRESENT(C, X) ((C).find() != (C).end())
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

using ll = unsigned long long;

/* ----------------------------- MAIN CODE ----------------------------- */

template <typename Container>
void filter_element(const Container &c, ll n, unordered_map<ll, typename Container::value_type> &mapping)
{
    ll idx = 0;
    while (n)
    {
        (n & 1) ? cout << mapping[idx] : cout << "";

        idx++;
        n = n >> 1;
    }
    cout << endl;
}

template <typename Container>
void generate_subset(const Container &c) // container must have random access iterator
{
    ll c_len = c.size();
    ll start = 0;
    ll end = (1 << c_len) - 1; // max possible subset would be 2^n - 1

    unordered_map<ll, typename Container::value_type> mapping;

    for (ll idx = 0; idx < c_len; idx++)
        mapping[idx] = c[idx];

    for (ll num = start; num <= end; num++)
    {
        filter_element(c, num, mapping);
    }
}

int main()
{
    vector<int> v = {1, 2, 3};
    generate_subset(v);
    return 0;
}
