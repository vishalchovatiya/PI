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

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

vector<ull> primeNoUptoN(ull n)
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

int main()
{
    vector<ull> primes = primeNoUptoN(20);
    PRINT(primes, cout << i << " ");
    return 0;
}
