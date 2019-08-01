/* 
SMART KEYPAD - I
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format:
A single string containing numbers only.

Constraints:
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
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
ll digit(char num)
{
    return num - '0';
}

vector<string> combination(vector<string> &v_str1, vector<string> &v_str2)
{
    vector<string> res;

    for (size_t idx1 = 0; idx1 < v_str1.size(); idx1++)
    {
        for (size_t idx2 = 0; idx2 < v_str2.size(); idx2++)
        {
            res.push_back(v_str1[idx1] + v_str2[idx2]);
        }
    }

    return res;
}

int main()
{
    vector<string> table[] = {{" "},
                              {".", "+", "@", "$"},
                              {"a", "b", "c"},
                              {"d", "e", "f"},
                              {"g", "h", "i"},
                              {"j", "k", "l"},
                              {"m", "n", "o"},
                              {"p", "q", "r", "s"},
                              {"t", "u", "v"},
                              {"w", "x", "y", "z"}};

    // vector<string> str1 = {"1", "2"};
    // vector<string> str2 = {"A", "B"};
    // vector<string> str3 = {"+", "x"};

    string str;
    getline(cin, str);

    auto it_r = str.rbegin();
    vector<string> res = table[digit(*it_r)];
    it_r++;

    while (it_r != str.rend())
    {
        res = combination(table[digit(*it_r)], res);
        it_r++;
    }
    // PRINT(res);
    for (auto &&str : res)
    {
        cout << str << endl;
    }

    return 0;
}
