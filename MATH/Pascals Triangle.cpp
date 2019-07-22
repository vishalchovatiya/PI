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

/* Pascal's Triangle line wise
0|    1
1|    1 1
2|    1 2 1
3|    1 3 3 1
4|    1 4 6 4 1
5|    1 5 10 10 5 1

Formula:

f(line,i) = f(line-1,i-1) + f(line-1,i)

 */

template <typename T>
void pascal_triangle_upto_line(T n)
{
}

int main()
{
    DEBUG(pascal_triangle(5));
    return 0;
}
