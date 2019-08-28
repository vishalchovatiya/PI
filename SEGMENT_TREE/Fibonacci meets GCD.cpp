
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

constexpr ull mod = 1e9 + 7;
constexpr ull MOD = 1e9 + 7;

#define matrix vector<vector<ll>>

matrix mul(matrix &A, matrix B)
{
    matrix C(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int x = 0; x < 2; x++)
                C[i][j] = (C[i][j] + A[i][x] * B[x][j]) % MOD;
        }
    }
    return C;
}

matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p & 1)
        return mul(A, pow(A, p - 1));
    matrix X = pow(A, p / 2);
    return mul(X, X);
}

ll fibo(ll n)
{
    if (!n)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    vector<ll> F1(2);
    F1[0] = F1[1] = 1;
    matrix T(2, vector<ll>(2));
    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;
    T = pow(T, n - 1);
    ll res = 0;
    for (int i = 0; i < 2; i++)
    {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res % MOD;
}

template <
    typename T,        /* Element types */
    typename operation /* Binary predicate(functor) */
    >
class segment_tree
{
    ull m_elements;
    vector<T> m_seg;
    vector<T> m_lazy;
    operation op;

    /* Utility methods ---------------------------------------------------------- */
    inline ull LEFT(ull root_idx) const { return (root_idx << 1); }
    inline ull RIGHT(ull root_idx) const { return (root_idx << 1) | 1; }

    void build(const vector<T> &arr, ull s, ull e, const ull idx);
    void update(const ull l, const ull r, T val, ull s, ull e, const ull idx = 1);
    T query(const ull l, const ull r, ull s, ull e, ull idx = 1);

public:
    /* Life --------------------------------------------------------------------- */
    segment_tree(const ull &&N);
    segment_tree(const vector<T> &arr);
    segment_tree(const initializer_list<T> &arr);

    /* APIs --------------------------------------------------------------------- */
    void update(const ull l, const ull r, T val);
    T query(const ull l, const ull r);
    void print() const;
};

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const ull &&N) : m_elements(N), m_seg(4 * N + 1, T()), m_lazy(4 * N + 1, T()) {}

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const vector<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 4 + 1, T()), m_lazy(arr.size() * 4 + 1, T())
{
    build(arr, 0, m_elements - 1, 1);
}

template <typename T, typename operation>
segment_tree<T, operation>::segment_tree(const initializer_list<T> &arr) : m_elements(arr.size()), m_seg(arr.size() * 4 + 1, T()), m_lazy(arr.size() * 4 + 1, T())
{
    vector<T> v_arr = arr;
    build(v_arr, 0, m_elements - 1, 1);
}

template <typename T, typename operation>
void segment_tree<T, operation>::build(const vector<T> &arr, ull s, ull e, const ull idx)
{
    if (s == e)
    {
        m_seg[idx] = arr[s];
        return;
    }

    auto mid = (s + e) / 2;
    build(arr, s, mid, LEFT(idx));
    build(arr, mid + 1, e, RIGHT(idx));

    m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
  
}

template <typename T, typename operation>
void segment_tree<T, operation>::update(const ull l, const ull r, T val)
{
    update(l, r, val, 0, m_elements - 1);
}

template <typename T, typename operation>
void segment_tree<T, operation>::update(const ull l, const ull r, T val, ull s, ull e, const ull idx)
{
    // Push down the updates
    if (m_lazy[idx] != T())
    {
        m_seg[idx] += val;
        if (s != e)
        {
            m_lazy[LEFT(idx)] += val;
            m_lazy[RIGHT(idx)] += val;
        }
        m_lazy[idx] = T();
    }

    // Out of range
    if (s > r || e < l)
    {
        return;
    }

    // Complete overlap
    if (s >= l && e <= r)
    {
        m_seg[idx] += val;
        if (s != e)
        {
            m_lazy[LEFT(idx)] += val;
            m_lazy[RIGHT(idx)] += val;
        }
        return;
    }

    // Partial overlap
    auto mid = (s + e) / 2;
    update(l, r, val, s, mid, LEFT(idx));
    update(l, r, val, mid + 1, e, RIGHT(idx));

    m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);
}

template <typename T, typename operation>
T segment_tree<T, operation>::query(const ull l, const ull r)
{
    return fibo(query(l, r, 0, m_elements - 1));
}

template <typename T, typename operation>
T segment_tree<T, operation>::query(const ull l, const ull r, ull s, ull e, ull idx)
{

    // No overlap
    if (s > e || s > r || e < l)
    {
        return -1;
    }

    // Complete overlap
    if (s >= l && e <= r)
    {
        return m_seg[idx];
    }

    // Partial overlap
    auto mid = (s + e) / 2;
    T min_l = query(l, r, s, mid, LEFT(idx));
    T min_r = query(l, r, mid + 1, e, RIGHT(idx));

    // m_seg[idx] = op(m_seg[LEFT(idx)], m_seg[RIGHT(idx)]);

    // if (min_l == -1)
    // return min_r;
    // if (min_r == -1)
    // return min_l;

    // DEBUG(min_l)
    // DEBUG(min_r)
    // DEBUG(op(min_l, min_r));
    return op(min_l, min_r);
}

template <typename T, typename operation>
void segment_tree<T, operation>::print() const
{
    // PRINT(m_seg)
    // PRINT(m_lazy)
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
        if ((*ele) == T() && (*(ele + 1)) == T())
            break;
    }
}

/* ------------------------------------------------------------------------------------- */

ll gcd(ll a, ll b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template <typename T>
struct compare
{
    inline T operator()(T l, T r)
    {
        return gcd(l, r);
    }
};

int main()
{
    // calculate_fib();
    ll N, Q;
    cin >> N >> Q;
    vector<ll> v(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    segment_tree<ll, compare<ll>> sg_t(v);
    // sg_t.print();

    for (ll i = 0; i < Q; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << sg_t.query(l - 1, r - 1) << endl;
        // DEBUG(sg_t.query(0, 2));
    }

    return 0;
}
