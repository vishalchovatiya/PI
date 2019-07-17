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

/*
    extended euclid's algo
    mmi only possible if gcd(a,b) = 1
 */

template <typename T>
T mmi(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    T gcd = mmi(b, a % b, x, y);

    T old_x = x;
    x = y;
    y = old_x - (a / b) * x;

    return gcd;
}

int main()
{
    ll Q;
    cin >> Q;

    ll a = Q;
    ll b = 1000000007;
    ll x = 0;
    ll y = 0;

    // DEBUG(mmi(a, b, x, y));
    ll gcd = mmi(a, b, x, y);

    cout << x << endl;
    // DEBUG(x);
    // DEBUG(y);
    return 0;
}

/* OUTPUT:
333333336
 */
