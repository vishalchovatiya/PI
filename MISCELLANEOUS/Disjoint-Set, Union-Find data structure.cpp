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

template <typename T = ll>
class disjoint_set
{
    using ll = long long;

    /* Data Members ---------------------------------------------------------------------*/
    struct node
    {
        T m_data;
        ll m_rank = 0;
        node *m_parent = nullptr;

        node(T data) : m_data(data) {}
    };

    using node_ptr = node *;

    map<T, node_ptr> m_dt_to_nd_ptr; // data to node pointers

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
    ll set_size(T data) const;
    map<T, set<T>> set_list() const;
};

template <typename T>
disjoint_set<T>::disjoint_set() {}
template <typename T>
disjoint_set<T>::~disjoint_set() {}

template <typename T>
T disjoint_set<T>::make_set(T data)
{
    auto temp = new node(data);
    temp->m_parent = temp;
    m_dt_to_nd_ptr[data] = temp;
    return temp->m_data;
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
    return find_parent(m_dt_to_nd_ptr[data])->m_data;
}

template <typename T>
T disjoint_set<T>::make_union(T data_1, T data_2)
{
    auto parent_1 = find_parent(m_dt_to_nd_ptr[data_1]);
    auto parent_2 = find_parent(m_dt_to_nd_ptr[data_2]);

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
map<T, set<T>> disjoint_set<T>::set_list() const
{
    map<T, set<T>> setid_to_set;

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
ll disjoint_set<T>::set_size(T data) const
{
    map<T, set<T>> setid_to_set;

    for (auto &&nd : m_dt_to_nd_ptr)
        setid_to_set[nd.second->m_parent->m_data].insert(nd.first);

    return setid_to_set[data].size();
}

int main()
{
    disjoint_set<ll> ds;

    ds.make_set(10);
    ds.make_set(11);
    ds.make_set(12);
    ds.make_set(13);

    ds.make_union(10, 11);
    ds.make_union(10, 12);

    DEBUG(ds.find_id(10));
    DEBUG(ds.find_id(11));
    DEBUG(ds.find_id(12));
    DEBUG(ds.find_id(13));

    // ds.make_union(10, 12);

    ds.print_sets();
    DEBUG(ds.set_size(10));

    return 0;
}
