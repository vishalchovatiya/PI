#include <bits/stdc++.h>

#define DEBUG(X) cout << #X << " = " << X << endl;
#define PRINT(C, WAY)                      \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            WAY;                           \
        }                                  \
        cout << endl;                      \
    } while (0);
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define PRESENT(C, X) ((C).find() != (C).end())

using ll = long long;
using namespace std;

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

int main()
{
    ll a = 3;
    ll m = 1000000007;

    // DEBUG(mmi(a, m));
    cout << mmi(a, m) << endl;

    return 0;
}

/* OUTPUT:
333333336
 */
