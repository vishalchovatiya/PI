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
using ull = unsigned long long;
using namespace std;

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extended_euclid(b, a % b, x, y);
    ll old_x = x;
    x = y;
    y = old_x - (a / b) * y;
    return gcd;
}

int main()
{
    ll x;
    ll y;
    ll gcd = extended_euclid(30, 20, x, y); // 30(1) + 20(-1) = 10

    DEBUG(gcd);
    DEBUG(x);
    DEBUG(y);

    return 0;
}

/* OUTPUT
gcd = 10
x = 1
y = -1
 */
