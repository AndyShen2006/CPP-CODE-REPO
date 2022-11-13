#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right;
};

Node tree[1000001];
int maxdep = 0;

void dfs(int i, int depth)
{
    maxdep = max(maxdep, depth);
    if (tree[i].left != 0) {
        dfs(tree[i].left, depth + 1);
    }
    if (tree[i].right != 0) {
        dfs(tree[i].right, depth + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l, r;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        tree[i].left = l;
        tree[i].right = r;
    }
    dfs(1, 1);
    cout << maxdep << endl;
    return 0;
}