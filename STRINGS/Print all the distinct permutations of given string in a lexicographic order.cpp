/*
TRICKY PERMUTATIONS
Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

NOTE: DO NOT USE MAP OR SET.

Input Format:
The first and only line of the test case contains the input string.

Constraints:
Length of the string <= 8

Output Format
Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

Sample Input
ABA
Sample Output
AAB
ABA
BAA
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
    o << pair.first << " -> " << pair.second << endl;
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

/*
    BC
  /    \
BC      CB


    BB
  /    \
BB      BB
 */

inline int to_int(char character)
{
    return character - 0;
}

vector<string> output;

void permut(char *str, int i, int size)
{
    if (i == (size - 1))
    {
        // cout << str << endl;
        output.push_back(string(str));
        return;
    }

    int is_permuted[300] = {0};

    for (int idx = i; idx < size; ++idx)
    {
        if (!is_permuted[to_int(str[idx])])
        {
            is_permuted[to_int(str[idx])] = true;
            swap(str[idx], str[i]);
            permut(str, i + 1, size);
            swap(str[i], str[idx]);
        }
    }
}

int main()
{
    string str;
    getline(cin, str);

    permut(const_cast<char *>(str.c_str()), 0, str.length());

    sort(ALL(output), [](string &lhs, string &rhs) {
        return lexicographical_compare(ALL(lhs), ALL(rhs));
    });

    for (auto &&str : output)
    {
        cout << str << endl;
    }

    return 0;
}
