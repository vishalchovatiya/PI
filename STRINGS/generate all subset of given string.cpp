#include <bits/stdc++.h>

#define DEBUG(X) std::cout << #X << " = " << X << std::endl;
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

void filterChar(char str[], ll n, unordered_map<ll, char> &mapping)
{
    ll idx = 0;
    while (n)
    {
        (n & 1) ? cout << mapping[idx] : cout << "";

        idx++;
        n = n >> 1;
    }
    cout << endl;
}

void generateSubset(char str[])
{
    ll start = 0;
    ll end = (1 << strlen(str)) - 1; // max possble subset would be 2^n - 1

    unordered_map<ll, char> mapping;
    for (ll charIdx = 0; charIdx < strlen(str); charIdx++)
        mapping[charIdx] = str[charIdx];

    for (ll num = start; num <= end; num++)
    {
        filterChar(str, num, mapping);
    }
}

int main()
{
    generateSubset("abc");
    return 0;
}
