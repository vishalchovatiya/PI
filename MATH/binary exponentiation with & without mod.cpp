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

template <typename T>
inline T is_odd(T n)
{
    return (n & 0x1);
}

/*
    2^n = (2^2)^n/2, for all even n
    2^n = 2 x (2^2)^n/2, for all odd n
 */
template <typename T>
T binary_exponentiation(T x, T n, T m = numeric_limits<T>::max()) // x^n in log(N) time
{
    T res = 1;
    while (n > 0)
    {
        if (is_odd(n))
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n = n / 2;
    }

    return res;
}

int main()
{
    DEBUG(binary_exponentiation(2, 0));    // ans = 1
    DEBUG(binary_exponentiation(2, 2));    // ans = 4
    DEBUG(binary_exponentiation(2, 3, 3)); // ans = 2

    return 0;
}
