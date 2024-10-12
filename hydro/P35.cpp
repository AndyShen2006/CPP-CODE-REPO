#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_M = 2e5 + 10;
typedef long long ll;

struct Node {
    int l, r;
    ll data;
    void show() const
    {
        cerr << "DEBUG INFO:" << endl;
        cerr << "{l,r,data}=" << l << ',' << r << ',' << data << endl;
    }
} segt[MAX_M << 2];

int a[MAX_M];

inline void push_up(int p)
{
    segt[p].data = max(segt[p << 1].data, segt[p << 1 | 1].data);
}

void build(int l, int r, int p)
{
    segt[p].data = INT_MIN;
    segt[p].l = l;
    segt[p].r = r;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
}

void modify(int l, int r, int p, ll data)
{
    if (segt[p].l == segt[p].r) {
        segt[p].data = data;
        return;
    }
    int mid = (segt[p].l + segt[p].r) >> 1;
    if (mid >= l) {
        modify(l, r, p << 1, data);
    }
    if (mid < r) {
        modify(l, r, p << 1 | 1, data);
    }
    push_up(p);
}

ll query(int l, int r, int p)
{
    if (l <= segt[p].l && segt[p].r <= r) {
        return segt[p].data;
    }
    int mid = (segt[p].l + segt[p].r) >> 1;
    ll lAns = 0, rAns = 0;
    if (mid >= l) {
        lAns = query(l, r, p << 1);
    }
    if (mid < r) {
        rAns = query(l, r, p << 1 | 1);
    }
    return max(lAns, rAns);
}

int main()
{
    // freopen("data/P35b.in", "r", stdin);
    // freopen("data/P35b.out", "w", stdout);
    int m, p;
    cin >> m >> p;
    build(1, m, 1);
    ll a = 0;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int L;
            cin >> L;
            a = query(cnt - L + 1, cnt, 1);
            cout << a << endl;
        } else if (op == 'A') {
            int t;
            cin >> t;
            ++cnt;
            modify(cnt, cnt, 1, (t + a) % p);
        } else {
            ;
        }
    }
    return 0;
}