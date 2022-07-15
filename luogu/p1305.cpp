#include <bits/stdc++.h>

using namespace std;

struct Node {
    char left = 0, right = 0;
};

Node tree[256];

void preorder(char root)
{
    cout << root;
    if (tree[root].left != 0) {
        preorder(tree[root].left);
    }
    if (tree[root].right != 0) {
        preorder(tree[root].right);
    }
}

int main()
{
    int n;
    cin >> n;
    char root;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (i == 1) {
            root = s[0];
        }
        if (s[1] != '*') {
            tree[s[0]].left = s[1];
        }
        if (s[2] != '*') {
            tree[s[0]].right = s[2];
        }
    }
    preorder(root);
    cout << endl;
    return 0;
}