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

    node *root = NULL;
    uint8_t bits = 4; // depth of tree

    bt() : root(new node) {}

    void add(ll value)
    {
        ll idx = (bits - 1);
        node *traverse = root;

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

    bool is_present(ll value)
    {
        ll idx = (bits - 1);
        node *traverse = root;

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
            if (cnt == (bits))
                cout << value << endl;
            return;
        }

        if (root->left != NULL)
            preorder_traversal(root->left, value, (cnt + 1));

        if (root->right != NULL)
            preorder_traversal(root->right, value | (1 << ((bits - 1) - cnt)), (cnt + 1));
    }

    void print()
    {
        preorder_traversal(root);
    }
};

int main()
{
    bt tree;
    tree.add(0);
    tree.add(1);
    tree.add(2);
    tree.add(5);
    DEBUG(tree.is_present(2));
    DEBUG(tree.is_present(4));
    DEBUG(tree.is_present(5));
    tree.print();
    return 0;
}
