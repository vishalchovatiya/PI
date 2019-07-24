/*
MAX XOR ARRAY: https://hack.codingblocks.com/practice/p/384/666

You are given an array containing n elements. Xor of an array is defined as the xor of all the elements present in the array. You can remove atmost one element from the array to maximize the value of XOR of array. Find the maximum XOR value you can get for the resulting array.

Input Format:
First line of input contains an integer n denoting the size of the array. After that n lines follow, where the i th line contains the i'th element of the array.

Constraints:
1 <= n <= 1000000 0 <= elements of array <= 10^18

Output Format
You have to print a single integer denoting the maximum xor you can get for the resulting array.

Sample Input
3
1
2
3
Sample Output
3
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
ostream &operator<<(ostream &o, pair<T, T> &pair) // To print map in PRINT
{
    o << pair.first << " " << pair.second << endl;
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
using namespace std;
struct bt
{
    /*
        - data not needed, coz leaf node represent value
        - edge represent binary value
        - store binary of integers in reverse matter i.e. 0,1,5, 0xF will be store as
                        0/  \1
                       0/  0/\1
                      0/   1\ \1
                     0/\1  0/  \1
        integers     0  1  5   0xF
    */
    struct node
    {
        node *left = NULL;  // mean 0
        node *right = NULL; // mean 1
    };

    node *m_root = NULL;
    uint8_t m_bits = 4; // depth of tree

    bt(uint8_t bits = 4) : m_root(new node), m_bits(bits) {}

    void add(ll value)
    {
        ll idx = (m_bits - 1);
        node *traverse = m_root;

        while (idx >= 0)
        {
            if (value & (1 << idx))
            {
                if (traverse->right == NULL)
                    traverse->right = new node;
                traverse = traverse->right;
            }
            else
            {
                if (traverse->left == NULL)
                    traverse->left = new node;
                traverse = traverse->left;
            }

            idx--;
        }
    }

    ll max_xor(ll xor_val)
    {
        ll res = 0;
        ll idx = (m_bits - 1);
        node *traverse = m_root;

        while (idx >= 0)
        {
            // if xor_val has zero goto right
            // else left

            if (xor_val & (1 << idx)) // 1
            {
                if (traverse->left != NULL)
                {
                    traverse = traverse->left;
                }
                else
                {
                    traverse = traverse->right;
                    res |= (1 << idx);
                }
            }
            else // 0
            {
                if (traverse->right != NULL)
                {
                    traverse = traverse->right;
                    res |= (1 << idx);
                }
                else
                {
                    traverse = traverse->left;
                }
            }

            idx--;
        }
        return res;
    }

    bool is_present(ll value)
    {
        ll idx = (m_bits - 1);
        node *traverse = m_root;

        while (idx >= 0)
        {
            if (value & (1 << idx))
            {
                if (traverse->right == NULL)
                    return false;
                traverse = traverse->right;
            }
            else
            {
                if (traverse->left == NULL)
                    return false;
                traverse = traverse->left;
            }

            idx--;
        }
        return true;
    }

    void preorder_traversal(node *root, ll value = 0, ll cnt = 0)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (cnt == (m_bits))
                cout << value << endl;
            return;
        }

        if (root->left != NULL)
            preorder_traversal(root->left, value, (cnt + 1));

        if (root->right != NULL)
            preorder_traversal(root->right, value | (1 << ((m_bits - 1) - cnt)), (cnt + 1));
    }

    void print()
    {
        preorder_traversal(m_root);
    }
};

int main()
{
    bt tree(64);
    ll xor_val = 0;
    ll n;
    read(n);

    for (ll i = 0; i < n; i++)
    {
        ll temp;
        read(temp);
        tree.add(temp);
        xor_val ^= temp;
    }

    cout << tree.max_xor(xor_val) << endl;

    return 0;
}
