/* 
SUM IT UP
You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.
Note:

All numbers (including target) will be positive integers
Elements in the combination must be in non-descending order
There should be no duplicate combinations
Input Format:
The first line will contain N indicating the number of elements in the array.
The second line will contain space separated N integers , A[i]. 
The third line will contain the target number T.

Constraints:
N <= 15 1<= A[I] <= 100

Output Format
Print all unique combinations of the numbers satisfying the above constraints in a separate line in lexicographic manner.

Sample Input
7
10 1 2 7 6 1 5
8
Sample Output
1 1 6 
1 2 5 
1 7 
2 6 
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
using vll = vector<ll>;
using sll = set<ll>;
using msll = multiset<ll>;
using mll = map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

/* --------------------------------------------------------------------- */

vector<msll> output;

void permut(vll &arr, ll num, ll start = 0, msll res = msll())
{
    if (num == 0)
    {
        output.push_back(res);
        return;
    }

    for (ll idx = start; idx < arr.size(); idx++)
    {
        auto &n = arr[idx];

        if ((n > num) || ((num - n) < 0))
            continue;

        // add
        res.insert(n);

        // permut
        permut(arr, num - n, idx + 1, res);

        // remove & backtrack
        res.erase(res.find(n));
    }
}

int main()
{
    ll size;
    cin >> size;

    vll arr(size);

    for (ll i = 0; i < size; i++)
    {
        ll temp;
        cin >> temp;
        arr[i] = temp;
    }

    ll num;
    cin >> num;

    permut(arr, num);

    sort(ALL(output));

    auto it_end = unique(ALL(output));

    for (auto it = output.begin(); it != it_end; ++it)
    {
        for (auto &&num : *it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
