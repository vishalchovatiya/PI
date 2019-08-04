/*
EXPAND THE POND
You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water such that any cell is accessible from any other cell by moving only along neighbours. You should add water to exactly one cell in order to maximise the size of the pond.


Input Format:
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell and 1 for a cell containing water.

Constraints:
1 ≤ N,M ≤ 1000
There is at least one dry cell and one cell filled with water in the matrix.

Output Format:
Print a single integer representing the largest possible size of the pond.

Sample Input:
3 3
0 1 1
0 0 1
0 1 0
Sample Output:
5
Explanation:
Watering the cell at coordinates [2,2] unites the 2 ponds with sizes 1 and 3, resulting a pond of size 5, including the newly watered cell.
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
using ull = unsigned long long;

using namespace std;

/* Example ----------------------------------------------------------------------------
3 x 3           3 x 4
0 1 1           0,  1,  2,  3
0 0 1           4,  5,  6,  7
0 1 0           8,  9, 10, 11
*/

template <typename T = ull>
class disjoint_set
{
    using ll = long long;
    using ull = unsigned long long;

    /* Data Members ---------------------------------------------------------------------*/
    struct node
    {
        T m_data;
        ull m_rank = 0;
        node *m_parent = nullptr;

        node(T data) : m_data(data) {}
    };

    using node_ptr = node *;

    unordered_map<T, node_ptr> m_dt_to_nd_ptr; // data to node pointers

public:
    /* Constructors ---------------------------------------------------------------------*/
    disjoint_set();
    ~disjoint_set();

    /* Utility Methods ---------------------------------------------------------------------*/
    void print_sets() const;

    /* APIs --------------------------------------------------------------------------*/
    T find_id(T data);
    node_ptr find_parent(node_ptr nd);
    T make_set(T data);
    T make_union(T data_1, T data_2);
    ull set_size(T data) const;
    unordered_map<T, unordered_set<T>> set_list() const;
};

template <typename T>
disjoint_set<T>::disjoint_set() {}
template <typename T>
disjoint_set<T>::~disjoint_set() {}

template <typename T>
T disjoint_set<T>::make_set(T data)
{
    if (m_dt_to_nd_ptr.find(data) == m_dt_to_nd_ptr.end())
    {
        auto temp = new node(data);
        temp->m_parent = temp;
        m_dt_to_nd_ptr[data] = temp;
        return temp->m_data;
    }
    return data;
}

template <typename T>
auto disjoint_set<T>::find_parent(typename disjoint_set<T>::node_ptr nd) -> typename disjoint_set<T>::node_ptr
{
    auto traverse = nd;

    while (nd != nd->m_parent) // Find parent
    {
        nd = nd->m_parent;
    }

    while (traverse != traverse->m_parent) // Set all node directly under parent
    {
        traverse->m_parent = nd;
        traverse = traverse->m_parent;
    }

    return traverse;
}

template <typename T>
T disjoint_set<T>::find_id(T data)
{
    return find_parent(m_dt_to_nd_ptr[make_set(data)])->m_data;
}

template <typename T>
T disjoint_set<T>::make_union(T data_1, T data_2)
{
    auto parent_1 = find_parent(m_dt_to_nd_ptr[make_set(data_1)]);
    auto parent_2 = find_parent(m_dt_to_nd_ptr[make_set(data_2)]);

    if (parent_1 == parent_2) // is of same union already
        return parent_1->m_data;

    if (parent_1->m_rank >= parent_2->m_rank)
    {
        parent_1->m_rank += (parent_1->m_rank == parent_2->m_rank) ? 1 : 0;
        parent_2->m_parent = parent_1;
        return parent_1->m_data;
    }
    else
    {
        parent_1->m_parent = parent_2;
        return parent_2->m_data;
    }
}

template <typename T>
unordered_map<T, unordered_set<T>> disjoint_set<T>::set_list() const
{
    unordered_map<T, unordered_set<T>> setid_to_set;

    for (auto &&nd : m_dt_to_nd_ptr)
        setid_to_set[nd.second->m_parent->m_data].insert(nd.first);

    return setid_to_set;
}

template <typename T>
void disjoint_set<T>::print_sets() const
{
    for (auto &&id_set : set_list())
    {
        cout << id_set.first << " -> ";
        for (auto &&val : id_set.second)
            cout << val << " ";
        cout << endl;
    }

    // cout << "Total sets = " << setid_to_vec.size() << endl;
}

template <typename T>
ull disjoint_set<T>::set_size(T data) const
{
    map<T, set<T>> setid_to_set;

    for (auto &&nd : m_dt_to_nd_ptr)
        setid_to_set[nd.second->m_parent->m_data].insert(nd.first);

    return setid_to_set[data].size();
}

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
    set<tuple<ull, ull>> get_neighbours(ull r, ull c);
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

set<tuple<ull, ull>> grid::get_neighbours(ull r, ull c)
{
    set<tuple<ull, ull>> res;
    // L
    if ((c > 0) && (c < m_c) && (r >= 0) && (r < m_r))
    {
        res.emplace(r, c - 1);
    }

    // R
    if ((c >= 0) && ((c + 1) < m_c) && (r >= 0) && (r < m_r))
    {
        res.emplace(r, c + 1);
    }

    // U
    if ((c >= 0) && (c < m_c) && (r > 0) && (r < m_r))
    {
        res.emplace(r - 1, c);
    }

    // D
    if ((c >= 0) && (c < m_c) && (r >= 0) && ((r + 1) < m_r))
    {
        res.emplace(r + 1, c);
    }

    return res;
}

int main()
{
    disjoint_set<ull> ds;

    ull r, c;
    cin >> r >> c;

    grid arr(r, c);

    for (ull r = 0; r < arr.get_row_count(); r++)
    {
        for (ull c = 0; c < arr.get_column_count(); c++)
        {
            cin >> arr[r][c];
        }
    }

    // grid arr = {
    //     {1, 1, 0},
    //     {0, 0, 0},
    //     {0, 1, 1},
    // };

    // Create set
    for (ull r = 0; r < arr.get_row_count(); r++)
    {
        for (ull c = 0; c < arr.get_column_count(); c++)
        {
            if (arr[r][c] == 1)
            {
                ull cell_no = arr.get_cell_no(r, c);
                ds.make_set(cell_no);
                // cout << cell_no << " -> ";
                for (auto &&neighbour : arr.get_neighbours(r, c))
                {
                    const ull &i = get<0>(neighbour);
                    const ull &j = get<1>(neighbour);
                    if (arr[i][j] == 1)
                    {
                        ull adjecent = arr.get_cell_no(i, j);
                        ds.make_union(cell_no, adjecent);
                        // cout << adjecent << " ";
                    }
                }
                // cout << endl;
            }
        }
    }

    // DEBUG("==============")

    // ds.print_sets();
    unordered_map<ull, unordered_set<ull>> set_list = ds.set_list();

    // for (auto &&id_set : set_list)
    // {
    //     cout << id_set.first << " -> ";
    //     for (auto &&val : id_set.second)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // DEBUG("==============")
    // DEBUG(set_list[0].max_size())

    ull max_pond_size = 0 /* self size */;

    // Create union & store max pond size
    for (ull r = 0; r < arr.get_row_count(); r++)
    {
        for (ull c = 0; c < arr.get_column_count(); c++)
        {
            if (arr[r][c] == 0)
            {
                ull cell_no = arr.get_cell_no(r, c);
                // DEBUG(cell_no);
                ull adjacent_pond_size = 1 /* self size */;
                unordered_set<ull> adjacent_ponds;

                for (auto &&neighbour : arr.get_neighbours(r, c))
                {
                    const ull &i = get<0>(neighbour);
                    const ull &j = get<1>(neighbour);
                    if (arr[i][j] == 1)
                    {
                        ull adjacent = arr.get_cell_no(i, j);
                        adjacent_ponds.emplace(ds.find_id(adjacent));
                        // DEBUG(ds.find_id(adjacent));
                    }
                }

                for_each(ALL(adjacent_ponds), [&](auto &&pond) {
                    adjacent_pond_size += set_list[pond].size();
                });

                max_pond_size = max(max_pond_size, adjacent_pond_size);
            }
            // DEBUG("===============")
        }
    }

    cout << max_pond_size << endl;

    return 0;
}
