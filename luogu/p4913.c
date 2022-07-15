#include <stdio.h>

struct Node {
    int left, right;
};

struct Node tree[1000001];
int maxdep = 0;

void dfs(int i, int depth)
{
    maxdep = maxdep > depth ? maxdep : depth;
    if (tree[i].left != 0) {
        dfs(tree[i].left, depth + 1);
    }
    if (tree[i].right != 0) {
        dfs(tree[i].right, depth + 1);
    }
}

int main()
{
    int n, l, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r);
        tree[i].left = l;
        tree[i].right = r;
    }
    dfs(1, 1);
    printf("%d\n", maxdep);
    return 0;
}