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
ostream &operator<<(ostream &o, pair<T, T> &pair) // To print map in PRINT
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

using ll = long long;
using namespace std;

/* MMI iterative

Euclid's algo ---------------------------------------------------------
gcd(a,b) = gcd(b, a%b)
gcd(a,0) = a    ------- base case

Extended Euclid's algo -----------------------------------------------

ax + by = gcd(a, b)
bx + (a%b)y = gcd(b, a%b)
.
.
.
ax + 0y = a   ------- base case

x = 1
y = 0

Value of x & y ------------------------------------------------------
bx + (a%b)y = gcd(b, a%b)
(a%b) = a - ⌊a/b⌋b
x = y1 - ⌊a/b⌋ * x1
y = x1

*/
template <typename T>
T mmi(T a, T m)
{
    T old_m = m;
    stack<pair<T, T>> ab;

    // GCD Euclid's algo
    while (m != 0)
    {
        ab.push(make_pair(a, m));
        T old_a = a;
        a = m;
        m = old_a % m;
    }

    // Calculating coefficient
    T x = 1;
    T y = 0;
    while (!ab.empty())
    {
        auto pair = ab.top();

        T old_x = x;
        x = y;
        y = (old_x - ((pair.first / pair.second) * y));

        ab.pop();
    }

    // Make x positive
    if (x < 0)
        x += old_m;

    return x;
}

/*
Chinese Remainder Theorem

x =  ( (rem[i]*pp[i]*inv[i]) + .... upto n-1) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of
         pp[i] with respect to num[i]

*/
ll linear_congruence(vector<ll> &mod, vector<ll> &rem)
{
    ll prod = accumulate(ALL(mod), 1, multiplies<ll>());

    ll x = 0;
    for (ll i = 0; i < mod.size(); i++)
    {
        ll pp_i = prod / mod[i];

        x += (rem[i] * pp_i * mmi(pp_i, mod[i]));
    }
    return x % prod;
}

int main()
{
    /*     ll Q;
    cin >> Q;
    vector<ll> mod(Q);
    vector<ll> rem(Q);

    for (ll i = 0; i < Q; i++)
    {
        ll temp;
        cin >> temp;
        mod[i] = temp;
    }

    for (ll i = 0; i < Q; i++)
    {
        ll temp;
        cin >> temp;
        rem[i] = temp;
    }
 */
    vector<ll> mod = {2, 3, 2};
    vector<ll> rem = {3, 5, 7};
    // ans = 23;
    // DEBUG(mmi(3, 1000000007));
    // DEBUG(mmi(20, 3));
    // DEBUG(linear_congruence(mod, rem));
    cout << linear_congruence(mod, rem) << endl;
    return 0;
}
