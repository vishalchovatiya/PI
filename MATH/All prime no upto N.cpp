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

template <typename T>
set<T> primeNoUpto(T n)
{
    set<T> res;

    bool is_prime[n + 1]{0};
    memset(is_prime, true, sizeof(is_prime));
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

    return res;
}

int main()
{
    vector<ull> primes = primeNoUpto(20);
    PRINT(primes, cout << i << " ");
    return 0;
}
