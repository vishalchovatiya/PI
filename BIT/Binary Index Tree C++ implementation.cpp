/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/
Fenwick Tree or Binary Indexed Tree by Tushar Roy on YouTube
Why it is called Binary Indexed Tree
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
#define SIZE_OF(ARR) (sizeof(ARR) / sizeof(ARR[0]))
#define ALL(C) (C).begin(), (C).end()
#define PRESENT(C, X) ((C).find() != (C).end())

using ll = long long;
using ull = unsigned long long;
ll mod = 1e9 + 7;

template <
    typename T,        /* Element types */
    typename operation /* Binary predicate(functor) */
    >
class binary_index_tree
{
    ull m_elements;
    vector<T> m_BIT;
    operation op;

    /* Utility methods ---------------------------------------------------------- */
    inline ull RIGHT_MOST_SET_BIT(ull bits)
    {
        return (bits & (-bits));
    }

public:
    /* Life --------------------------------------------------------------------- */
    binary_index_tree(const vector<T> &arr) : m_elements(arr.size()), m_BIT(arr.size() + 1, T())
    {
        for (ull idx = 0; idx < arr.size(); ++idx)
            update(idx + 1, arr[idx]);
    }

    binary_index_tree(const initializer_list<T> &arr) : binary_index_tree(vector<T>(arr))
    {
    }

    /* APIs --------------------------------------------------------------------- */
    void update(ull idx, T val)
    {
        for (; idx <= m_elements; idx += RIGHT_MOST_SET_BIT(idx))
        {
            m_BIT[idx] = op(m_BIT[idx], val);
        }
    }

    T query(ll idx)
    {
        T ans = 0;
        for (; idx > 0; idx -= RIGHT_MOST_SET_BIT(idx))
        {
            ans = op(ans, m_BIT[idx]);
        }
        return ans;
    }

    T query(ll l, ll r)
    {
        return query(r) - query(l - 1);
    }

    void print()
    {
        PRINT(m_BIT)
    }
};

template <typename T>
struct compare
{
    T operator()(T &l, T &r)
    {
        return l + r;
    }
};

int main()
{
    binary_index_tree<ll, compare<ll>> bit = {5, 3, 7, 2, 1};

    bit.print();

    DEBUG(bit.query(2, 3));
    DEBUG(bit.query(1, 5));

    return 0;
}
