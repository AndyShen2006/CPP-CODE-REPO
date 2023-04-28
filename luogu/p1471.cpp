#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
struct Node {
    int l, r;
    double psum, sum;
    double add;
} st[4 * MAX_N];
double data[MAX_N];

void update(int pos)
{
    st[pos].psum = st[pos << 1].psum + st[pos << 1 | 1].psum;
    st[pos].sum = st[pos << 1].sum + st[pos << 1 | 1].sum;
}

void build(int pos, int l, int r)
{
    // printf("%d:[%d,%d]\n", pos, l, r);
    st[pos] = { l, r, 0, 0, 0 };
    if (l == r) {
        st[pos].sum = data[l];
        st[pos].psum = data[l] * data[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(pos << 1, l, mid);
    build(pos << 1 | 1, mid + 1, r);
    update(pos);
}

void pushDown(int pos)
{
    // Calculate current data
    st[pos << 1].psum += st[pos << 1].sum * st[pos].add * 2 + st[pos].add * st[pos].add * (st[pos << 1].r - st[pos << 1].l + 1);
    st[pos << 1].sum += st[pos].add * (st[pos << 1].r - st[pos << 1].l + 1);
    st[pos << 1 | 1].psum += st[pos << 1 | 1].sum * st[pos].add * 2 + st[pos].add * st[pos].add * (st[pos << 1 | 1].r - st[pos << 1 | 1].l + 1);
    st[pos << 1 | 1].sum += st[pos].add * (st[pos << 1 | 1].r - st[pos << 1 | 1].l + 1);
    // Push labels down
    st[pos << 1].add += st[pos].add;
    st[pos << 1 | 1].add += st[pos].add;
    // Clear labels
    st[pos].add = 0;
}

void add(int pos, int x, int y, double k)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        st[pos].add += k;
        st[pos].psum += 2 * k * st[pos].sum + k * k * (st[pos].r - st[pos].l + 1);
        st[pos].sum += k * (st[pos].r - st[pos].l + 1);
        return;
    }
    pushDown(pos);
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        add(pos << 1, x, y, k);
    }
    if (mid < y) {
        add(pos << 1 | 1, x, y, k);
    }
    update(pos);
}

double queryPsum(int pos, int x, int y)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        return st[pos].psum;
    }
    pushDown(pos);
    double psum = 0;
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        psum += queryPsum(pos << 1, x, y);
    }
    if (mid < y) {
        psum += queryPsum(pos << 1 | 1, x, y);
    }
    return psum;
}

double querySum(int pos, int x, int y)
{
    if (x <= st[pos].l && st[pos].r <= y) {
        return st[pos].sum;
    }
    pushDown(pos);
    double sum = 0;
    int mid = (st[pos].l + st[pos].r) >> 1;
    if (x <= mid) {
        sum += querySum(pos << 1, x, y);
    }
    if (mid < y) {
        sum += querySum(pos << 1 | 1, x, y);
    }
    return sum;
}

int main()
{
    freopen("data/p1471c.in", "r", stdin);
    freopen("data/p1471c.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    build(1, 1, n);
    // for (int i = 1; i <= 10; i++) {
    //     printf("[%d,%d],psum:%f,sum:%f\n", st[i].l, st[i].r, st[i].psum, st[i].sum);
    // }
    // exit(0);
    int op, x, y;
    double k;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            add(1, x, y, k);
        } else if (op == 2) {
            cin >> x >> y;
            cout << fixed << setprecision(4) << querySum(1, x, y) / (y - x + 1) << endl;
        } else {
            cin >> x >> y;
            double psum = queryPsum(1, x, y);
            double sum = querySum(1, x, y);
            double cnt = y - x + 1;
            cout << fixed << setprecision(4) << (psum - sum * sum / cnt) / cnt << endl;
        }
        // cout << op << ' ' << x << ' ' << y << endl;
        // for (int i = 1; i <= 4 * n; i++) {
        //     // printf("[%d,%d]:psum:%f;sum:%f;add:%f\n", st[i].l, st[i].r, st[i].psum, st[i].sum, st[i].add);
        //     printf("[%d,%d]:sum:%f;add:%f\n", st[i].l, st[i].r, st[i].sum, st[i].add);
        // }
        // for (int i = 1; i <= n; i++) {
        //     cout << querySum(1, i, i) << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << queryPsum(1, i, i) << ' ';
        // }
        // cout << endl;
    }
    return 0;
}