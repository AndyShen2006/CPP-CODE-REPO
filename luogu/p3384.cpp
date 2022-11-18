#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 1e5;
ll MOD;
int val[MAX_N]; // Order:After dfn
struct Node {
    int l, r;
    ll sum, add;
} st[4 * MAX_N];

inline void update(int pos)
{
    st[pos].sum = (st[pos << 1].sum + st[pos << 1 | 1].sum) % MOD;
}
void build(int pos, int l, int r)
{
    st[pos] = { l, r, 0, 0 };
    if (l == r) {
        st[pos].sum = val[l] % MOD;
        return;
    }
    int mid = (l + r) >> 1;
    build(pos << 1, l, mid);
    build(pos << 1 | 1, mid + 1, r);
    update(pos);
}
void pushDown(int pos)
{
    st[pos << 1].sum = (st[pos << 1].sum + (st[pos << 1].r - st[pos << 1].l + 1) * st[pos].add) % MOD;
    st[pos << 1 | 1].sum = (st[pos << 1 | 1].sum + (st[pos << 1 | 1].r - st[pos << 1 | 1].l + 1) * st[pos].add) % MOD;
    st[pos << 1].add = (st[pos << 1].add + st[pos].add) % MOD;
    st[pos << 1 | 1].add = (st[pos << 1 | 1].add + st[pos].add) % MOD;
    st[pos].add = 0;
}
void add(int pos, int x, int y, int k)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        st[pos].sum = (st[pos].sum + k * (st[pos].r - st[pos].l + 1)) % MOD;
        st[pos].add = (st[pos].add + k) % MOD;
        return;
    }
    pushDown(pos);
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        add(pos << 1, x, y, k);
    }
    if (y > mid) {
        add(pos << 1 | 1, x, y, k);
    }
    update(pos);
}
ll query(int pos, int x, int y)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        return st[pos].sum;
    }
    pushDown(pos);
    ll val = 0;
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        val = (val + query(pos << 1, x, y)) % MOD;
    }
    if (y > mid) {
        val = (val + query(pos << 1 | 1, x, y)) % MOD;
    }
    return val;
}

/*--------Segment Tree Above------------*/

vector<int> G[MAX_N];
int dfn[MAX_N], rdfn[MAX_N];
int depth[MAX_N], par[MAX_N], size[MAX_N], son[MAX_N], top[MAX_N], cnt;

void dfs1(int x, int f)
{
    par[x] = f;
    size[x] = 1;
    depth[x] = depth[f] + 1;
    int tSize;
    for (auto it : G[x]) {
        if (it == f) {
            continue;
        }
        dfs1(it, x);
        size[x] += size[it];
        if (size[it] > tSize) {
            size[it] = tSize;
            son[x] = it;
        }
    }
}

void dfs2(int x, int f)
{
    top[x] = f;
    dfn[x] = ++cnt;
    if (val[x] != 0) {
        add(1, dfn[x], dfn[x], val[x]);
    }
    if (son[x] == 0) {
        return;
    }
    dfs2(son[x], f);
    for (auto it : G[x]) {
    }
}
/*----Heavy Light Decomposition Above---*/

int main()
{
    int n, m, r;
    cin >> n >> m >> r >> MOD;

    return 0;
}