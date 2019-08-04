
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
using ull = unsigned long long;
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
    using ull = unsigned long long;
    using cell_no = ull;

    /* Data Members ---------------------------------------------------------------------*/
    ull m_r;
    ull m_c;
    ll **m_arr;

public:
    /* Constructors ---------------------------------------------------------------------*/
    grid(ull r, ull c);
    grid(initializer_list<initializer_list<ll>> const &arr);
    ~grid();

    /* Operator [][] ---------------------------------------------------------------------*/
    class proxy
    {
    public:
        proxy(ll *m_array) : m_array(m_array) {}

        ll &operator[](ull idx)
        {
            return m_array[idx];
        }

    private:
        ll *m_array;
    };

    proxy operator[](const ull idx)
    {
        return proxy(m_arr[idx]);
    }

    /* APIs ---------------------------------------------------------------------------*/
    inline cell_no get_cell_no(ull r, ull c) const;
    inline auto get_row_column(cell_no no) const -> tuple<ull, ull>;
    void print() const;
    inline ull get_row_count() const { return m_r; };
    inline ull get_column_count() const { return m_c; };
    set<cell_no> get_neighbours(cell_no no);
    set<tuple<ull, ull>> get_neighbours(ll r, ll c);
    void flood_fill(ll r, ll c, ll prev_r, ll prev_c, ll val);
    void flood_fill(ll r, ll c, ll val);
};

grid::grid(ull r, ull c) : m_r(r), m_c(c)
{
    m_arr = new ll *[r + 10];
    for (ll i = 0; i < r; i++)
    {
        m_arr[i] = new ll[c + 10];
    }
}

grid::grid(initializer_list<initializer_list<ll>> const &arr) : grid(arr.size(), arr.begin()->size())
{
    ull r = 0;
    for (auto &&list : arr)
    {
        ull c = 0;
        for (auto &&ele : list)
        {
            m_arr[r][c++] = ele;
        }
        r++;
    }
}

grid::~grid()
{
}

inline typename grid::cell_no grid::get_cell_no(ull r, ull c) const
{
    return r * m_c + c;
}

inline auto grid::get_row_column(typename grid::cell_no no) const -> tuple<ull, ull>
{
    ull r = (no / m_c);
    ull c = (no % m_c);
    return make_tuple(r, c);
}

void grid::print() const
{
    for (ull r = 0; r < m_r; r++)
    {
        for (ull c = 0; c < m_c; c++)
        {
            cout << setw(3) << m_arr[r][c];
        }
        cout << endl;
    }
}

set<typename grid::cell_no> grid::get_neighbours(typename grid::cell_no no)
{
    auto ij = get_row_column(no);

    set<typename grid::cell_no> res;

    for (auto &&neighbour : get_neighbours(get<0>(ij), get<1>(ij)))
    {
        res.emplace(get_cell_no(get<0>(neighbour), get<1>(neighbour)));
    }

    return res;
}

set<tuple<ull, ull>> grid::get_neighbours(ll r, ll c)
{
    static constexpr int d_r[] = {0, 0, -1, +1}; // direction row
    static constexpr int d_c[] = {-1, +1, 0, 0}; // direction column
    set<tuple<ull, ull>> res;

    for (size_t i = 0; i < 4; i++)
    {
        auto new_row = r + d_r[i];
        auto new_column = c + d_c[i];

        if ((new_row >= 0) && (new_row < m_r))
            if ((new_column >= 0) && (new_column < m_c))
                res.emplace(new_row, new_column);
    }

    return res;
}

void grid::flood_fill(ll r, ll c, ll val)
{
    flood_fill(r, c, r, c, val);
}
void grid::flood_fill(ll r, ll c, ll prev_r, ll prev_c, const ll val)
{
    m_arr[r][c] = val;

    for (auto &&tuple_ij : get_neighbours(r, c))
    {
        auto &i = get<0>(tuple_ij);
        auto &j = get<1>(tuple_ij);

        if (!((i == prev_r) && (j == prev_c)))
        {
            if (m_arr[i][j] == 1)
            {
                flood_fill(i, j, r, c, val);
            }
        }
    }
}

int main()
{
    // grid arr = {
    // {0, 1, 2, 3},
    // {4, 5, 6, 7},
    // {8, 9, 10, 11},
    // };
    grid arr = {
        {1, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
    };

    arr.flood_fill(0, 0, 2);

    arr.print();

    /*
    for (auto &&tup : arr.get_neighbours(5))
    {
        cout << tup << endl;
    }
    auto ij = arr.get_row_column(11);
    DEBUG(get<0>(ij));
    DEBUG(get<1>(ij));

    DEBUG(arr.get_cell_no(0, 0));
    DEBUG(arr.get_cell_no(1, 1));
    DEBUG(arr.get_cell_no(2, 3));
 */
    return 0;
}
