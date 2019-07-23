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

using ll = unsigned long long;

ll get_no_of_query();
/* -------------------------  MAIN CODE  -------------------------- */
vector<ll> smallest_prime_factor;
ll primes_upto = 100000000;

/*
index: 0  | 1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15
prime: -1 | -1 | 2 | 3 | 2 | 5 | 2 | 7 | 2 | 3 | 2  | 11 | 2  | 13 | 2  | 3
Note: Could multiple as well
 */
template <typename T>
T *precomp_small_primes_factor_upto(T n)
{
    T *prime_list = new T[(n + 1)];
    memset(prime_list, -1, sizeof(T) * (n + 1));

    for (T d = 2; d <= n; d++)
    {
        prime_list[d] = min(d, prime_list[d]);

        for (T i = (d * d); i <= n; i += d)
        {
            prime_list[i] = min(d, prime_list[i]);
        }
    }

    return prime_list;
}

/*
    GCD of more than two no is product of their common prime factors-
*/
ll GCD(vector<ll> &nums)
{
    static is_precomp_prime_factors = false;
    if (!is_precomp_prime_factors)
    {
        ll *smallest_prime_factor = precomp_small_primes_factor_upto(primes_upto);
        is_precomp_prime_factors = true;
    }

    ll ans = 1;
    map<ll, ll> factor_cnt;

    for (auto n : nums)
    {
        // Calculate factors of n
        map<ll, ll> factors_n;
        while (n > 1)
        {
            factors_n[smallest_prime_factor[n]];
            n /= smallest_prime_factor[n];
        }

        // Add factors to main factor list
        for_each(ALL(factors_n), [&](auto &fctr) { factor_cnt[fctr.first]++; });
    }

    // Multiply all common factors
    for_each(ALL(factor_cnt), [&](auto &fctr) {
        if (fctr.second == nums.size())
        {
            ans *= fctr.first;
        }
    });

    return ans;
}

int main()
{
    // auto Q = get_no_of_query();

    vector<ll> nums = {2, 8, 6};
    DEBUG(GCD(nums));
    return 0;
}

ll get_no_of_query()
{
    ll Q;
    cin >> Q;
    return Q;
}
