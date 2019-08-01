/* 
GENERATE PARENTHESES
Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.
Input Format:
Single line containing an integral value 'n'.
Constraints:
1<=n<=11
Output Format
Print the balanced parentheses strings with every possible solution on new line.
Sample Input
2
Sample Output
()() 
(()) 
*/
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

template <typename... T>
void read(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T... args)
{
    ((cout << args), ...);
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

/* --------------------------------------------------------------------- */

void generateParenthesis(int n, int openB, int closeB, string str) {
    if(closeB == n) {
        cout<<str<<endl;
        return;
    }
    if(openB > closeB) {
        generateParenthesis(n, openB, closeB+1, str+')');
    }
    if(openB < n) {
        generateParenthesis(n, openB+1, closeB, str+'(');
    }
}

int main(int argc, char const *argv[])
{
    generateParenthesis(3, 0, 0, "");
    return 0;
}

