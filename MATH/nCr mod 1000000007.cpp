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

/* -------------------------  MAIN CODE  -------------------------- */

template <typename T>
T binary_exponentiation(T x, T n, T mod = numeric_limits<T>::max())
{
    T ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        n = n >> 1;
    }
    return ans;
}

/*
    If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.
    a^(m-1) ≡ 1 (mod m)
    If we multiply both sides with a^(-1), we get
    a^(-1) ≡ a^(m-2) (mod m)
 */
template <typename T>
T mmi(T a, T m)
{
    return binary_exponentiation(a, m - 2, m);
}

/* Pascal's Triangle line wise
0|    1
1|    1 1
2|    1 2 1
3|    1 3 3 1
4|    1 4 6 4 1
5|    1 5 10 10 5 1

Note: each cell in pascal triangle is nCr, where n = line no, r = cell no in that line

Formula:

C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
Just substitute value of line! from expression 2 to expression 1

C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time
 */

template <typename T>
T nCr(T n, T r, T mod = numeric_limits<T>::max()) //time complexity O(N^2), space O(1)
{
    T &line = n;

    T C = 1;
    for (T i = 1; i <= r; i++)
    {
        // C = C * (line - i + 1) /i; // operation broke in to two pieces for taking mode
        C = (C * (line - i + 1)) % mod;
        C = (C * mmi(i, mod)) % mod;
    }
    return C;
}

int main()
{
    ll mod = 1000000007;
    ll n = 0;
    ll r = 0;
    cin >> n;
    cin >> r;
    cout << nCr(n, r, mod) << endl;
    // DEBUG(nCr(n, r, mod));
    return 0;
}
