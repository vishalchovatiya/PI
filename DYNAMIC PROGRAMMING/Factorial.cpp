/*
		Factorial formula N! = N x (N-1)!
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
T get_factorial_of(T n, T max_upto = 10000)
{
    bool is_precomp = false;
    T *factorial = new T[max_upto];
    is_precomp = false;

    factorial[0] = factorial[1] = 1;

    for (T i = 2; i <= n; i++)
    {
        factorial[i] = i * factorial[i - 1];
    }

    return factorial[n];
}

int main()
{
    DEBUG(get_factorial_of(3));
    return 0;
}
