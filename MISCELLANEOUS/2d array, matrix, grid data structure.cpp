
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

/* Example ----------------------------------------------------------------------------
3 x 3           3 x 4
0 1 1           0,  1,  2,  3
0 0 1           4,  5,  6,  7
0 1 0           8,  9, 10, 11
*/

class grid
{
    /* Typedefs -------------------------------------------------------------------------*/
    using ll = long long;

    /* Data Members ---------------------------------------------------------------------*/
    ll m_r;
    ll m_c;
    vector<vector<ll>> m_arr;

public:
    /* Constructors ---------------------------------------------------------------------*/
    grid(ll r, ll c);
    grid(initializer_list<initializer_list<ll>> const &arr);
    ~grid();

    /* Operator [][] ---------------------------------------------------------------------*/
    class proxy
    {
    public:
        proxy(vector<ll> &m_array) : m_array(m_array) {}

        ll &operator[](ll index)
        {
            return m_array[index];
        }

    private:
        vector<ll> &m_array;
    };

    proxy operator[](const ll idx)
    {
        return proxy(m_arr[idx]);
    }

    /* APIs ---------------------------------------------------------------------------*/
    inline ll get_node_no(ll r, ll c) const;
    inline auto get_row_column(ll node_no) const -> tuple<ll, ll>;
    void print() const;
    inline ll get_row_count() const { return m_r; };
    inline ll get_column_count() const { return m_c; };
};

grid::grid(ll r, ll c) : m_r(r), m_c(c), m_arr(r, vector<ll>(c))
{
}

grid::grid(initializer_list<initializer_list<ll>> const &arr) : grid(arr.size(), (*arr.begin()).size())
{
    auto it = m_arr.begin();
    for_each(ALL(arr), [&](auto &l) {
        *it++ = l;
    });
}

grid::~grid()
{
}

inline ll grid::get_node_no(ll r, ll c) const
{
    return r * m_c + c;
}

inline auto grid::get_row_column(ll node_no) const -> tuple<ll, ll>
{
    ll r = (node_no / m_c);
    ll c = (node_no % m_c);
    return make_tuple(r, c);
}

void grid::print() const
{
    for (ll r = 0; r < m_r; r++)
    {
        for (ll c = 0; c < m_c; c++)
        {
            cout << setw(3) << m_arr[r][c];
        }
        cout << endl;
    }
}

int main()
{
    grid arr = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
    };

    arr[2][3] = 11;

    arr.print();

    auto ij = arr.get_row_column(11);
    DEBUG(get<0>(ij));
    DEBUG(get<1>(ij));

    DEBUG(arr.get_node_no(0, 0));
    DEBUG(arr.get_node_no(1, 1));
    DEBUG(arr.get_node_no(2, 3));

    return 0;
}
