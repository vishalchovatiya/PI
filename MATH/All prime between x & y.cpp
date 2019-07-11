
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

// 0, 1, 2, 3, 4, 5, 6
// 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36

vector<ull> primeNoUpto(ull n)
{
    vector<ull> res;

    bool isPrime[n + 1]{0};

    isPrime[2] = true;

    for (ull num = 3; num <= n; num = num + 2)
    {
        isPrime[num] = true;
    }

    for (ull num = 3; num <= n; num = num + 2)
    {
        if (isPrime[num])
        {
            for (ull i = num * num; i <= n; i += num)
            {
                isPrime[i] = false;
            }
        }
    }

    for (ull num = 0; num <= n; num++)
        if (isPrime[num])
            res.push_back(num);

    return res;
}

vector<ull> primeNoBetween(ull x, ull y)
{
    vector<ull> res;

    ull rangeSize = y - x;
    bool isPrime[rangeSize]{0};

    memset(isPrime, true, sizeof(isPrime));

    for (auto &&div : primeNoUpto(sqrt(y)))
    {
        for (ull num = x; num <= y; num++)
        {
            if ((num % div) == 0)
                isPrime[num - x] = false;
        }
    }

    for (ull num = 0; num <= (rangeSize); num++)
        if (isPrime[num])
            res.push_back(num + x);

    return res;
}

int main()
{
    vector<ull> primes = primeNoBetween(25, 36);
    PRINT(primes, cout << i << " ");
    return 0;
}
