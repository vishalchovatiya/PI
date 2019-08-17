/*
https://codeforces.com/blog/entry/18051
Build:
- Element at index i in original array will be at index (i + N) in the segment tree array.
- Now to calculate the parents, we will start from index (N – 1) and move upward.
- We will take total of 2*N memory for segment tree(without lay propagation)

Query: [x,y)
- If l, the left interval border, is odd (which is equivalent to l&1) then l is the right child of its parent. Then our interval includes node l but doesn't include it's parent.
- So we add seg[l] and move to the right of l's parent by setting l = (l + 1) / 2.
- If l is even, it is the left child, and the interval includes its parent as well (unless the right border interferes), so we just move to it by setting l = l / 2.
- Similar argumentation is applied to the right border. We stop once borders meet.

Lazy/Delay Propagation:
- We store update on segment(internal nodes which represent segment) rather than leaf nodes.
- Push down update on necessary nodes on query
- Need one more array(let say d[N]) of size N to store delayed operation results for leaves. This leads us to a total of 3 * N memory use for complete segment tree.
- Previously we could say that seg[i] is a value corresponding to it's segment. Now it's not entirely true — first we need to apply all the delayed operations on the route from node i to the root of the tree (parents of node i). We assume that seg[i] already includes d[i], so that route starts not with i but with its direct parent.


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

#define LAZY

template <
    typename T,        /* Element types */
    typename operation /* Binary predicate(functor) */
    >
class segment_tree
{
    ull m_elements;
    vector<T> m_seg;
    vector<T> m_delay;
    operation op;

    /* Utility methods ---------------------------------------------------------- */
    inline ull LEFT(ull root_idx) const { return (root_idx << 1); }
    inline ull RIGHT(ull root_idx) const { return (root_idx << 1) | 1; }
    inline ull PARENT(ull child_idx) const { return (child_idx >> 1); }
    inline ull SIBLING(ull child_idx) const { return (child_idx ^ 1); }

    inline bool IS_RIGHT(ull root_idx) const { return (root_idx & 1); }
    inline bool IS_LEFT(ull root_idx) const { return !IS_RIGHT(root_idx); }

    void apply(ull p, T val);
#ifdef LAZY
    void push(ull p);
#endif
public:
    /* Life --------------------------------------------------------------------- */
    segment_tree(const vector<T> &arr);
    segment_tree(const initializer_list<T> &arr);

    /* APIs --------------------------------------------------------------------- */
    T query(ull l, ull r);
    void update(ull l, ull r, T val);
    void print() const;
};

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const vector<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 2), m_delay(arr.size(), 0)
{
    // Set original array in leaf nodes
    copy(ALL(arr), m_seg.begin() + arr.size());

    // Create parents
    for (ull idx = arr.size() - 1; idx > 0; --idx)
        m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
}

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const initializer_list<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 2), m_delay(arr.size(), 0)
{
    // Set original array in leaf nodes
    copy(ALL(arr), m_seg.begin() + arr.size());

    // Create parents
    for (ull idx = arr.size() - 1; idx > 0; --idx)
        m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
}

template <typename T, typename operation>
void segment_tree<T, operation>::apply(ull p, T val)
{
    m_seg[p] += val;
#ifdef LAZY
    if (p < m_elements)
        m_delay[p] += val;
#endif
}

#ifdef LAZY
template <typename T, typename operation>
void segment_tree<T, operation>::update(ull l, ull r, T val)
{
    l += m_elements, r += m_elements;
    auto old_l = l;
    auto old_r = r;

    for (; l < r; l = PARENT(l), r = PARENT(r))
    {
        if (IS_RIGHT(l))
            apply(l++, val);
        if (IS_RIGHT(r))
            apply(--r, val);
    }

    // Update all the parents of a given node
    static auto build = [this](ull p) {
        while (p > 1)
            p = PARENT(p), m_seg[p] = op(m_seg[LEFT(p)], m_seg[RIGHT(p)]) + m_delay[p];
    };

    build(old_l);
    build(old_r - 1);
}

#else

template <typename T, typename operation>
void segment_tree<T, operation>::update(ull l, ull r, T val)
{
    l += m_elements, r += m_elements;

    for (ll i = l; i < r; ++i)
        m_seg[i] += val;

    for (ull i = l; i < r; ++i)
        for (ull idx = i; idx > 1; idx = PARENT(idx))
            m_seg[PARENT(idx)] = op(m_seg[idx], m_seg[SIBLING(idx)]);
}

#endif

#ifdef LAZY
/*
`push()` propagates changes from all the parents of a given node down the tree starting from the root. This parents are exactly the prefixes of p in binary notation, that's why we use binary shifts to calculate them.
*/
template <typename T, typename operation>
void segment_tree<T, operation>::push(ull p)
{
    ull h = log2(m_elements);

    for (ull s = h; s > 0; --s)
    {
        ull i = p >> s;
        // DEBUG(i)
        if (m_delay[i] != 0)
        {
            apply(LEFT(i), m_delay[i]);
            apply(RIGHT(i), m_delay[i]);
            m_delay[i] = 0;
        }
    }
}
#endif

template <typename T, typename operation>
T segment_tree<T, operation>::query(ull l, ull r)
{
    l += m_elements, r += m_elements;
#ifdef LAZY
    push(l);
    push(r - 1);
#endif
    T res = numeric_limits<T>::max();

    for (; l < r; l = PARENT(l), r = PARENT(r))
    {
        if (IS_RIGHT(l))
            res = op(res, m_seg[l++]);
        if (IS_RIGHT(r))
            res = op(res, m_seg[--r]);
    }

    return res;
}

template <typename T, typename operation>
void segment_tree<T, operation>::print() const
{
    // PRINT(m_seg)
    // PRINT(m_delay)
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
        // return l + r;
    }
};

int main()
{
    segment_tree<ll, compare<ll>> sg_t{1, 8, 3, 7};
    // sg_t.print();
    // DEBUG(sg_t.query(0, 4));
    sg_t.update(2, 3, 10);
    sg_t.print();

    // DEBUG("=====================")
    DEBUG(sg_t.query(0, 4));
    sg_t.print();

    return 0;
}
