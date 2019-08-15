/*
Build:
- Element at index i in original array will be at index (i + N) in the segment tree array.
- Now to calculate the parents, we will start from index (N – 1) and move upward

Query:
- If l in query is right child consider only seg[l] node, discard left subtree completely
-

Note: This code with work for min & max, for sum & other operations need to change query method
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

template <
    typename T,        /* Element types */
    typename operation /* Binary predicate(functor) */
    >
class segment_tree
{
    ull m_elements;
    vector<T> m_seg;
    operation op;

    /* Utility methods ---------------------------------------------------------- */

    inline ull LEFT(ull root_idx) const { return (root_idx << 1); }
    inline ull RIGHT(ull root_idx) const { return (root_idx << 1) | 1; }
    inline ull PARENT(ull child_idx) const { return (child_idx >> 1); }
    inline ull SIBLING(ull child_idx) const { return (child_idx ^ 1); }

public:
    /* Life --------------------------------------------------------------------- */
    segment_tree(const vector<T> &arr);
    segment_tree(const initializer_list<T> &arr);

    /* APIs --------------------------------------------------------------------- */
    T query(ull l, ull r);
    void update(ull i, ull val);
    void print() const;
};

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const vector<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 2)
{
    // Set original array in leaf nodes
    copy(ALL(arr), m_seg.begin() + arr.size());

    // Create parents
    for (ull idx = arr.size() - 1; idx > 0; --idx)
        m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
}

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const initializer_list<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 2)
{
    // Set original array in leaf nodes
    copy(ALL(arr), m_seg.begin() + arr.size());

    // Create parents
    for (ull idx = arr.size() - 1; idx > 0; --idx)
        m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
}

template <typename T, typename operation>
T segment_tree<T, operation>::query(ull l, ull r)
{
    l = l + m_elements;
    r = r + m_elements;
    T res = m_seg[l];

    while (l < r)
    {
        if (l & 1)
            res = op(res, m_seg[l]);
        if (r & 1)
            res = op(res, m_seg[r]);
        l = PARENT(l);
        r = PARENT(r);
    }

    return res = op(res, m_seg[r]);
}

template <typename T, typename operation>
void segment_tree<T, operation>::update(ull i, ull val)
{
    i = i + m_elements;
    m_seg[i] = val;

    for (ull idx = i; idx > 1; idx = PARENT(idx))
        m_seg[PARENT(idx)] = op(m_seg[idx], m_seg[SIBLING(idx)]);
}

template <typename T, typename operation>
void segment_tree<T, operation>::print() const
{
    // PRINT(m_seg)
    ull level = 0;

    for (auto ele = m_seg.begin() + 1; ele < m_seg.end();)
    {
        ull ele_on_level = (1 << level++);
        while (ele_on_level-- && ele != m_seg.end())
        {
            cout << *ele << " ";
            ele++;
        }
        cout << endl;
    }
}

/* ------------------------------------------------------------------------------------- */

template <typename T>
struct compare
{
    T operator()(T &l, T &r)
    {
        return min(l, r);
    }
};

int main()
{
    segment_tree<ll, compare<ll>> sg_t{1, 8, 3, 7};
    sg_t.update(0, 12);
    sg_t.print();
    DEBUG(sg_t.query(0, 1));

    return 0;
}
