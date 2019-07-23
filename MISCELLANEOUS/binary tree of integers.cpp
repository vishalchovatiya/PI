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
    o << pair.first << " " << pair.second << endl;
    return o;
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

ll get_no_of_query();
/* -------------------------  MAIN CODE  -------------------------- */

struct bt
{
    /*
        - data not needed, coz leaf node represent value
    */
    struct node
    {
        node *left = NULL;  // mean 0
        node *right = NULL; // mean 1
    };

    node *root = NULL;

    bt() : root(new node) {}

    void add(ll value)
    {
        ll idx = 3;
        node *traverse = root;

        while (idx >= 0) // 0...1
        {
            if (value & (1 << idx))
            {
                if (traverse->right == NULL)
                    traverse->right = new node;
                traverse = traverse->right;
                DEBUG("RIGHT");
            }
            else
            {
                if (traverse->left == NULL)
                    traverse->left = new node;
                traverse = traverse->left;
                DEBUG("LEFT");
            }

            idx--;
        }
    }

    void preorder_traversal(node *root, int value = 0, int cnt = 0)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (cnt == (4))
                cout << cnt << " " << hex << value << endl;
            return;
        }

        if (root->left != NULL)
            preorder_traversal(root->left, value, (cnt + 1));

        if (root->right != NULL)
            preorder_traversal(root->right, value | (1 << cnt), (cnt + 1));
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
    // tree.add(3);
    tree.print();
    return 0;
}
