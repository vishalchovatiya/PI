/* 
READ THE PAGES
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.

Input Format:
First line contains integers, N and M, denoting the number of books and number of students respectively. Next line contains N integers, denoting the number of pages in N books.

Constraints:
1<=N<=10^5 1<=M<=N 1<=Pi<=10^9

Output Format
Print a single integer, denoting the answer.

Sample Input
4 2
10 20 30 40
Sample Output
60
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
#include <memory>
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
#define SIZE_OF(ARR) (sizeof(ARR) / sizeof(ARR[0]))
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
using ull = unsigned long long;
using vll = vector<ll>;
using sll = set<ll>;
using msll = multiset<ll>;
using mll = map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

bool validate(vll &arr, ll mid, const ll students)
{
    ll sum = 0;
    ll p = 1;

    for (auto &&board_sz : arr)
    {
        // cout << board_sz << " ";
        if ((sum + board_sz) > mid)
        {
            sum = board_sz;
            p++;
            if (p > students)
                return false;
        }
        else
        {
            sum += board_sz;
        }
    }
    // cout << endl;
    // DEBUG(p)

    return true;
    // return ((p + 1) == students);
}

ll search(vll &arr, ll s, ll e, const ll students)
{
    bool last = true;
    ll mid = -1;
    // DEBUG("__________________________")
    while (s <= e)
    {
        mid = (s + e) / 2;
        // DEBUG(mid)

        if (validate(arr, mid, students))
        {
            // DEBUG("LEFT")
            last = true;
            e = mid - 1;
        }
        else
        {
            // DEBUG("RIGHT")
            last = false;
            s = mid + 1;
        }
        // DEBUG("=============")
        // break;
    }

    return (last == false) ? mid + 1 : mid;
}

int main()
{
    ll Q = 1;
    // cin >> Q;
    while (Q--)
    {
        ll books, students;
        cin >> books;
        cin >> students;
        vll arr(books);

        ll min_val = numeric_limits<ll>::min(), max_val = 0;
        for (ll i = 0; i < books; i++)
        {
            ll pages;
            cin >> pages;
            arr[i] = (pages);

            min_val = max(min_val, pages);
            max_val += pages;
        }

        // PRINT(arr)
        // DEBUG(min_val)
        // DEBUG(max_val)
        cout << search(arr, min_val, max_val, students);
    }

    return 0;
}
