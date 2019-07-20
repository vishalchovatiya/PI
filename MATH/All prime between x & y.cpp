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
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

/* ------------------------- HELPERS DEFINE -------------------------- */
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

ll get_no_of_query();

template <typename T>
vector<T> get_array(T Q);

/* ----------------------------- MAIN CODE ----------------------------- */

template <typename T>
set<T> primes_upto(T n)
{
    set<T> res;

    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (T num = 2; num <= n; num++)
    {
        if (is_prime[num])
        {
            res.insert(num);
            for (T i = num * num; i <= n; i += num)
            {
                is_prime[i] = false;
            }
        }
    }

    return res;
}

void segmented_sieve(ll S, ll E)
{
    if (S < 2)
        S = 2;

    ll range_size = E - S + 1;
    bool is_prime[range_size] = {0};
    ll sqrt_E = sqrt(E);
    auto primes = primes_upto(sqrt_E);

    // PRINT(primes);

    for (ll n = S; n <= E; n++)
    {
        is_prime[n - S] = true;
        for (auto &&prime_no : primes)
        {
            if (n == prime_no)
                break;

            if ((n % prime_no) == 0)
            {
                is_prime[n - S] = false;
                break;
            }
        }
        if (is_prime[n - S])
            cout << (n) << endl;
    }
}

int main()
{
    auto Q = get_no_of_query();

    for (ll i = 0; i < Q; i++)
    {
        auto arr = get_array(2);
        segmented_sieve(arr[0], arr[1]);
        if (i != (Q - 1))
            cout << endl;
    }

    return 0;
}

/* -------------------- HELPERS IMPLEMENTATION ------------------------ */
ll get_no_of_query()
{
    ll Q;
    cin >> Q;
    return Q;
}

template <typename T>
vector<T> get_array(T Q)
{
    vector<T> res(Q);

    for (T i = 0; i < Q; i++)
    {
        T temp;
        cin >> temp;
        res[i] = temp;
    }

    return res;
}
