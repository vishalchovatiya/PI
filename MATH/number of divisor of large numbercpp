/*
NUMBER OF DIVISORS

Little Bob and Mary once got into a fight over rating on codeforces. Bob asked Mary to share her ice-cream with him if she couldn't answer the question. Mary agreed as she was so confident of herself. Bob asked you are given a number n find its number of divisors. Mary answered it in a flash and started laughing. Bob said the question isn't over yet. Since n can be as large as having 50 digits you are only given some numbers <= 1000000 whose product is n. Mary got a bit surprised and started working on the question. Now you have to help Mary find the number of divisors of (a1* a2* a3 ….an) where you are given a1 a2 a3.. an. Since the answer can be large output it modulo 10^9+7.

Input Format:

first line consist of number of test cases. First line of every text case consists of integer n. the second line consists of n integers.

Constraints:

1 <= n <= 15 1 <= ai <= 1000000 1 <= test cases <= 10

Output Format

the number of divisors modulo 10^9 + 7.

Sample Input

3
3
13 50 70
3
22 41 60
2
5 5

Sample Output

48
64
3
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

    bool *is_prime(new bool[n + 1]);
    memset(is_prime, true, sizeof(bool) * (n + 1));

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

    delete[] is_prime;

    return res;
}

void no_of_divisors(ll N, map<ll, ll> &factor_cnt, ll mod = numeric_limits<ll>::max(), ll precomp_primes_upto = 1000000)
{
    ll res = 1;

    /* precompute primes ------------------------------------------ */
    static set<ll> primes;
    static bool is_pre_cal_prime = false;
    if (!is_pre_cal_prime)
    {
        primes = primes_upto(precomp_primes_upto);
        is_pre_cal_prime = true;
    }
    /* ------------------------------------------------------------ */

    for (auto &&prime : primes)
    {
        while ((N % prime) == 0)
        {
            N /= prime;
            factor_cnt[prime]++;
        }
        if (N <= 1)
            break;
    }
}

ll no_of_divisors(vector<ll> &arr, ll mod = numeric_limits<ll>::max())
{
    ll res = 1;
    map<ll, ll> factor_cnt;

    for (auto &&no : arr)
    {
        no_of_divisors(no, factor_cnt, mod);
    }

    for (auto &&factor : factor_cnt)
    {
        res = (res * (factor.second + 1)) % mod;
    }

    return res;
}

int main()
{
    ll mod = 1000000007ull;
    ll precomp_prime_upto = 1000000;

    auto Q = get_no_of_query();

    for (ll i = 0; i < Q; i++)
    {
        auto nos = get_no_of_query();

        auto arr = get_array(nos);
        cout << no_of_divisors(arr, mod) << endl;
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
