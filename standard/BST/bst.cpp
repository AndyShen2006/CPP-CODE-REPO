// Primary Binary Search Tree
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    char lData = '\0';
    Node() = default;
    explicit Node(char c)
    {
        lData = c;
    };
};

Node root;

void put(char c, Node* cur)
{
    if (c >= cur->lData) {
        if (cur->r == nullptr) {
            Node* nNode = new Node;
            cur->r = nNode;
            cur->r->lData = c;
        } else {
            put(c, cur->r);
        }
    } else {
        if (cur->l == nullptr) {
            Node* nNode = new Node;
            cur->l = nNode;
            cur->l->lData = c;
        } else {
            put(c, cur->l);
        }
    }
}

bool get(char c, Node* cur)
{
    if (cur == nullptr) {
        return false;
    }
    if (cur->lData == c) {
        return true;
    } else if (c < cur->lData) {
        return get(c, cur->l);
    } else {
        return get(c, cur->r);
    }
    return false;
}

void preorder(Node* cur)
{
    if (cur == nullptr) {
        return;
    }
    cout << cur->lData;
    preorder(cur->l);
    preorder(cur->r);
}

int main()
{
    // freopen("data/bst1.in", "r", stdin);
    string str;
    cin >> str;
    root.lData = str.front();
    for (int i = 1; i < str.size(); i++) {
        put(str[i], &root);
    }
    preorder(&root);
    cout << endl;
    int n;
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        cout << get(c, &root) << endl;
    }
    return 0;
}