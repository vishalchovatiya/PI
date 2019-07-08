#include <bits/stdc++.h>

#define DEBUG(X) std::cout << #X << " = " << X << std::endl;
#define PRINT(C, WAY)                      \
    do                                     \
    {                                      \
        cout << setw(10) << #C << " : \n"; \
        for (auto &&i : C)                 \
        {                                  \
            WAY;                           \
        }                                  \
        cout << endl;                      \
    } while (0);
#define ALL(C) (C).begin(), (C).end()
#define RALL(C) (C).rbegin(), (C).rend()
#define PRESENT(C, X) ((C).find() != (C).end())

using ll = long long;
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int x = 0) : data(x), left(NULL), right(NULL) {}
};

void traversalIterative(node *root)
{
    unordered_map<node *, int> cnt;
    stack<node *> S;

    S.push(root);

    while (!S.empty())
    {
        node *curr = S.top();

        if (curr == NULL)
        {
            S.pop();
            continue;
        }

        if (cnt[curr] == 0)cout << curr->data << " ";            
        else if (cnt[curr] == 1)S.push(curr->left);            
        else if (cnt[curr] == 2)S.push(curr->right);
        else S.pop();
        cnt[curr]++;
    }
    cout << endl;
}

int main()
{
    node *root = new node(10);

    root->left = new node(5);
    root->right = new node(12);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->right->left = new node(11);
    root->right->right = new node(17);

    traversalIterative(root);

    return 0;
}
