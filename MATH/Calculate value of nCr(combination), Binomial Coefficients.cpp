/*
nCr = n! / (r! . (n-r)!)
*/

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
#define PRESENT(C, X) ((C).find(X) != (C).end())

using ll = long long;
using namespace std;

template <typename T>
T factorial(T n, T max_upto = 10000, T mod = numeric_limits<T>::max())
{
    static bool is_precomp = false;
    static T *factorial = new T[max_upto];

    if (is_precomp)
        return factorial[n];

    factorial[0] = factorial[1] = 1;

    for (T i = 2; i <= n; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % mod;
    }

    is_precomp = true;
    return factorial[n];
}

ll nCr(ll n, ll r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    DEBUG(nCr(3, 2));
    return 0;
}
