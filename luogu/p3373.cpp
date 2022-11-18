#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod;
struct Node {
    int l, r;
    ll sum, mul, add;
} st[400020];
int a[100010];

void update(int pos)
{
    st[pos].sum = (st[pos << 1].sum + st[pos << 1 | 1].sum) % mod;
}

void build(int pos, int l, int r)
{
    st[pos] = { l, r, 0, 1, 0 };
    if (l == r) {
        st[pos].sum = a[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(pos << 1, l, mid);
    build(pos << 1 | 1, mid + 1, r);
    update(pos);
}

void pushDown(int pos)
{
    st[pos << 1].sum = (st[pos << 1].sum * st[pos].mul + st[pos].add * (st[pos << 1].r - st[pos << 1].l + 1)) % mod;
    st[pos << 1 | 1].sum = (st[pos << 1 | 1].sum * st[pos].mul + st[pos].add * (st[pos << 1 | 1].r - st[pos << 1 | 1].l + 1)) % mod;

    st[pos << 1].mul = (st[pos << 1].mul * st[pos].mul) % mod;
    st[pos << 1 | 1].mul = (st[pos << 1 | 1].mul * st[pos].mul) % mod;

    st[pos << 1].add = (st[pos << 1].add * st[pos].mul + st[pos].add) % mod;
    st[pos << 1 | 1].add = (st[pos << 1 | 1].add * st[pos].mul + st[pos].add) % mod;

    st[pos].add = 0;
    st[pos].mul = 1;
}

void multiply(int pos, int x, int y, int k)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        st[pos].add = st[pos].add * k % mod;
        st[pos].sum = st[pos].sum * k % mod;
        st[pos].mul = st[pos].mul * k % mod;
        return;
    }
    pushDown(pos);
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        multiply(pos << 1, x, y, k);
    }
    if (y > mid) {
        multiply(pos << 1 | 1, x, y, k);
    }
    update(pos);
}

void add(int pos, int x, int y, int k)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        st[pos].add = (st[pos].add + k) % mod;
        st[pos].sum = (st[pos].sum + k * (st[pos].r - st[pos].l + 1)) % mod;
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
        val = (val + query(pos << 1, x, y)) % mod;
    }
    if (y > mid) {
        val = (val + query(pos << 1 | 1, x, y)) % mod;
    }
    return val;
}

int main()
{
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, x, y, k;
        cin >> opt >> x >> y;
        switch (opt) {
        case 1:
            cin >> k;
            multiply(1, x, y, k);
            break;
        case 2:
            cin >> k;
            add(1, x, y, k);
            break;
        case 3:
            cout << query(1, x, y) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}