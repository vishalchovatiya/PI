/*
VIVEK AND FACTORS
Vivek loves to play number games with his friend Ujjawal. One day they were playing a game where one of them will speak out a positive number and the other have to tell the sum of its factors. The first one to say it correctly wins. After a while they got bored and wanted to try out a different game. Vivek then suggested about trying the reverse. That is, given a positive number 'S' , they have to find a number whose factors add up to 'S'. Realizing that this task is tougher than the original task, Vivek came to you for help. Luckily Vivek owns a portable programmable device and you have decided to burn a program to this device. Given the value of 'S' as input to the program, it will output a number whose sum of factors equal to 'S' .

Input Format:
There are several cases . Each case of input will consist of a positive integer 'S'<= 100000 . The last case is followed by a value of 0 .

Constraints:
0 < S <= 10000

Output Format
print the integer whose factors sum is equal to 'S'. Print the largest Integer whose factors sum is 'S' . If no such number exists, output '-1' .

Sample Input
1
102
1000
0
Sample Output
1
101
-1
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

int main()
{
    ll max = 20;
    map<ll, ll> fsum_to_num;
    vector<ll> v((max + 1), 1);
    ll i, j;

    v[0] = 0;
    v[1] = 1;

    fsum_to_num.insert(make_pair(v[0], 0));
    fsum_to_num.insert(make_pair(v[1], 1));

    for (i = 2; i <= max; i++)
    {
        v[i] += i;
        for (j = 2 * i; j <= max; j += i)
            v[j] += i;

        if (!PRESENT(fsum_to_num, v[i])) // if sum of factors unique
        {
            fsum_to_num.insert(make_pair(v[i], i));
        }
        else
        {
            if (i > fsum_to_num[v[i]]) // if sum already exist, then add large int
                fsum_to_num[v[i]] = i;
        }
    }

    PRINT(fsum_to_num);
    return 0;
}
