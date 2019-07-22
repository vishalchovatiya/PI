#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

/* ------------------------- HELPERS DEFINE -------------------------- */
template <typename T>
ostream &operator<<(ostream &o, pair<const T, T> &pair) // To print map in PRINT
{
    o << pair.first << " " << pair.second << endl;
    return o;
}

#define DEBUG(X) cout << #X << " = " << X << endl;
#define PRINT(C)                           \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            cout << i << " ";              \
        }                                  \
        cout << endl;                      \
    } while (0);
#define ALL(C) (C).begin(), (C).end()
#define PRESENT(C, X) ((C).find(X) != (C).end())
#define BENCHMARK(f)         \
    do                       \
    {                        \
        cout << #f << " = "; \
        benchmark(f);        \
    } while (0);

const auto benchmark = [](function<void(void)> f) {
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    f();
    cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << " microseconds\n";
};

using ll = unsigned long long;

/* Pascal's Triangle line wise
0|    1
1|    1 1
2|    1 2 1
3|    1 3 3 1
4|    1 4 6 4 1
5|    1 5 10 10 5 1

Formula:

f(0,0) = 1
f(line,i) = f(line-1,i-1) + f(line-1,i)

line length or no of elements in line = line no + 1

*/

template <typename T>
void pascal_triangle_matrix(T n) //O(n^2) time and O(n^2) extra space
{
    T C[n + 1][n + 1];
    C[0][0] = 1;
    // cout << C[0][0] << "\n";
    for (T line = 1; line <= n; ++line)
    {
        C[line][0] = C[line][line] = 1;
        // cout << C[line][0] << " ";
        for (T i = 1; i < line; ++i)
        {
            C[line][i] = C[line - 1][i - 1] + C[line - 1][i];
            // cout << C[line][i] << " ";
        }
        // cout << C[line][line] << "\n";
    }
}

/*
Formula:

C(line, i)   = line! / ( (line-i)! * i! )
C(line, i-1) = line! / ( (line - i + 1)! * (i-1)! )
We can derive following expression from above two expressions.
Just substitute value of line! from expression 2 to expression 1

C(line, i) = C(line, i-1) * (line - i + 1) / i

So C(line, i) can be calculated from C(line, i-1) in O(1) time
 */

template <typename T>
void pascal_triangle(T n) //time complexity O(N^2), space O(1)
{
    for (T line = 0; line <= (n); line++)
    {
        T C = 1;
        for (T i = 1; i <= line; i++)
        {
            // cout << C << " ";
            C = C * (line - i + 1) / i;
        }
        // cout << 1 << "\n";
    }
}

int main()
{
    pascal_triangle_matrix(5);
    pascal_triangle(5);
    return 0;
}
