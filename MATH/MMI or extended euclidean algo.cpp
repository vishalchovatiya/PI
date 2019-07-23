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
ostream &operator<<(ostream &o, pair<T, T> &pair) // To print map in PRINT
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

using ll = long long;
using namespace std;

/* MMI recursive
*/
template <typename T>
T mmi(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    T gcd = mmi(b, a % b, x, y);

    T old_x = x;
    x = y;
    y = old_x - (a / b) * x;

    return gcd;
}

/* MMI iterative

Euclid's algo ---------------------------------------------------------
gcd(a,b) = gcd(b, a%b)
gcd(a,0) = a    ------- base case

Extended Euclid's algo -----------------------------------------------

ax + by = gcd(a, b)
bx + (a%b)y = gcd(b, a%b)
.
.
.
ax + 0y = a   ------- base case

x = 1
y = 0

Value of x & y ------------------------------------------------------
bx + (a%b)y = gcd(b, a%b)
(a%b) = a - ⌊a/b⌋b
x = y1 - ⌊a/b⌋ * x1
y = x1

We basically start with base condition & do bottom-up approach

*/
template <typename T>
T mmi(T a, T m)
{
    T old_m = m;
    stack<pair<T, T>> ab;

    // GCD Euclid's algo
    while (m != 0)
    {
        ab.push(make_pair(a, m));
        T old_a = a;
        a = m;
        m = old_a % m;
    }

    // Calculating coefficient
    T x = 1;
    T y = 0;
    while (!ab.empty())
    {
        auto pair = ab.top();

        T old_x = x;
        x = y;
        y = (old_x - ((pair.first / pair.second) * y));

        ab.pop();
    }

    // Make x positive
    if (x < 0)
        x += old_m;

    return x;
}

int main()
{
    // DEBUG(mmi(3, 1000000007));
    DEBUG(mmi(3, 11));
    // DEBUG(mmi(11, 3));
    return 0;
}
