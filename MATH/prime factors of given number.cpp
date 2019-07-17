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
index: 0  | 1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15
prime: -1 | -1 | 2 | 3 | 2 | 5 | 2 | 7 | 2 | 3 | 2  | 11 | 2  | 13 | 2  | 3

Note: Could multiple as well
 */
template <typename T>
vector<T> precomputed_primes_upto(T n)
{
    vector<T> prime_list((n + 1), numeric_limits<T>::max());

    for (T d = 2; d <= n; d++)
    {
        prime_list[d] = min(d, prime_list[d]); // self divisible

        for (T i = (d * d); i <= n; i += d)
        {
            prime_list[i] = min(d, prime_list[i]);
        }
    }

    // PRINT(prime_list, cout << i << " ")
    return prime_list;
}

template <typename T>
vector<T> smallest_prime_factors_of(T n) // can return multiple
{
    vector<T> prime_list = precomputed_primes_upto(n);
    vector<T> prime_factors;

    while (n > 1)
    {
        // DEBUG(prime_list[n]);
        prime_factors.push_back(prime_list[n]);
        n /= prime_list[n];
    }

    return prime_factors;
}

int main()
{
    PRINT(smallest_prime_factors_of(15), cout << i << " ");
    PRINT(smallest_prime_factors_of(12), cout << i << " ");
    return 0;
}

/* OUTPUT:

smallest_prime_factors_of(15) :
3 5
smallest_prime_factors_of(12) :
2 2 3

 */
