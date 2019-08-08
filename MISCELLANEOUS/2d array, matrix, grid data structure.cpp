
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

#define SIZE_OF(ARR) (sizeof(ARR) / sizeof(ARR[0]))
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
using umll = unordered_map<ll, ll>;
using mmll = multimap<ll, ll>;
using namespace std;

/* Example ----------------------------------------------------------------------------
3 x 3           3 x 4
0 1 1           0,  1,  2,  3
0 0 1           4,  5,  6,  7
0 1 0           8,  9, 10, 11
*/

template <typename T = ll>
class grid
{
    /* Typedefs -------------------------------------------------------------------------*/
    using cell_no = ull;

    /* Data Members ---------------------------------------------------------------------*/
    ull m_r;
    ull m_c;
    T **m_arr;

public:
    /* Constructors ---------------------------------------------------------------------*/
    grid(ull r, ull c);
    grid(initializer_list<initializer_list<T>> const &arr);
    ~grid();

    /* Operator [][] ---------------------------------------------------------------------*/
    class proxy
    {
    public:
        proxy(T *m_array) : m_array(m_array) {}

        T &operator[](ull c)
        {
            return m_array[c];
        }

    private:
        T *m_array;
    };

    proxy operator[](const ull r)
    {
        return proxy(m_arr[r]);
    }

    /* APIs ---------------------------------------------------------------------------*/
    inline cell_no get_cell_no(ull r, ull c) const;
    inline auto get_row_column(cell_no no) const -> tuple<ull, ull>;
    void print() const;
    inline ull get_row_count() const { return m_r; };
    inline ull get_column_count() const { return m_c; };
    tuple<set<tuple<ull, ull>>, set<cell_no>> get_neighbours_row_col(ull r, ull c);
    set<cell_no> get_neighbours(cell_no no);
    set<tuple<ull, ull>> get_neighbours(ull r, ull c);

    ull flood_fill(cell_no no, T pattern = 0, T replace = 0);
    ull flood_fill(cell_no no, T pattern, T replace, umll &explored);
};

template <typename T>
grid<T>::grid(ull r, ull c) : m_r(r), m_c(c)
{
    m_arr = new T *[r];
    for (ull i = 0; i < r; i++)
    {
        m_arr[i] = new T[c];
        memset(m_arr[i], 0, sizeof(T) * c);
    }
}

template <typename T>
grid<T>::grid(initializer_list<initializer_list<T>> const &arr) : grid(arr.size(), arr.begin()->size())
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

template <typename T>
grid<T>::~grid()
{
}

template <typename T>
inline typename grid<T>::cell_no grid<T>::get_cell_no(ull r, ull c) const
{
    return r * m_c + c;
}

template <typename T>
inline auto grid<T>::get_row_column(typename grid<T>::cell_no no) const -> tuple<ull, ull>
{
    ull r = (no / m_c);
    ull c = (no % m_c);
    return make_tuple(r, c);
}

template <typename T>
void grid<T>::print() const
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

template <typename T>
set<typename grid<T>::cell_no> grid<T>::get_neighbours(typename grid<T>::cell_no no)
{
    auto ij = get_row_column(no);

    return get<1>(get_neighbours_row_col(get<0>(ij), get<1>(ij)));
}

template <typename T>
set<tuple<ull, ull>> grid<T>::get_neighbours(ull r, ull c)
{
    return get<0>(get_neighbours_row_col(r, c));
}

template <typename T>
tuple<set<tuple<ull, ull>>, set<typename grid<T>::cell_no>> grid<T>::get_neighbours_row_col(ull r, ull c)
{
    static constexpr int d_r[] = {0, 0, -1, +1, /* diagonals */ -1, -1, +1, +1}; // direction row
    static constexpr int d_c[] = {-1, +1, 0, 0, /* diagonals */ -1, +1, +1, -1}; // direction column
    set<tuple<ull, ull>> res_ij;

    set<typename grid<T>::cell_no> res_cell_no;

    for (size_t i = 0; i < (sizeof(d_r) / sizeof(d_r[0])); i++)
    {
        auto new_row = r + d_r[i];
        auto new_column = c + d_c[i];

        if ((new_row >= 0) && (new_row < m_r))
        {
            if ((new_column >= 0) && (new_column < m_c))
            {
                res_ij.emplace(new_row, new_column);
                res_cell_no.emplace(get_cell_no(new_row, new_column));
            }
        }
    }

    return make_tuple(res_ij, res_cell_no);
}
/*
template <typename T>
ull grid<T>::flood_fill(ll r, ll c, , ll val, unordered_map<ll, ll> &&explored_r = unordered_map<ll, ll>(), unordered_map<ll, ll> &&explored_c = unordered_map<ll, ll>())
{
    ull recur_cnt = 1;

    m_arr[r][c] = val;

    for (auto &&tuple_ij : get_neighbours(r, c))
    {
        auto &i = get<0>(tuple_ij);
        auto &j = get<1>(tuple_ij);

        if (!((i == prev_r) && (j == prev_c)))
        {
            if (m_arr[i][j] == 1)
            {
                recur_cnt += flood_fill(i, j, r, c, val);
            }
        }
    }
    return recur_cnt;
}
 */
template <typename T>
ull grid<T>::flood_fill(cell_no no, T pattern, T replace)
{
    umll explored;
    return flood_fill(no, pattern, replace, explored);
}

template <typename T>
ull grid<T>::flood_fill(cell_no no, T pattern, T replace, umll &explored)
{
    ull recur_cnt = 1;

    for (auto &&cell : get_neighbours(no))
    {
        if (!explored[cell])
        {
            explored[cell] = 1;

            auto ij = get_row_column(cell);
            auto &r = get<0>(ij);
            auto &c = get<1>(ij);

            if (m_arr[r][c] == pattern)
            {
                m_arr[r][c] = replace;
                flood_fill(cell, pattern, replace, explored);
            }
        }
    }
    return recur_cnt;
}

int main()
{
    // grid<char> arr = {
    // {0, 1, 2},
    // {3, 4, 5},
    // {6, 7, 8},
    // };

    grid<char> arr = {
        {'X', 'O', 'X'},
        {'X', 'O', 'X'},
        {'X', 'O', 'X'},
    };
    arr.print();

    DEBUG(arr.flood_fill(4, 'X', 'O'));

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
