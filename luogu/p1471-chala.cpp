#include <bits/stdc++.h>
using namespace std;
#define MAXN 114514
#define int long long

struct node {
    double sum, psum, lzt = 0;
} t[MAXN << 2];

int n, q;
double a[MAXN];

inline void pushup(int x)
{
    t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
    t[x].psum = t[x * 2].psum + t[x * 2 + 1].psum;
    return;
}

inline void pushdown(int x, int len)
{
    t[x * 2].psum += 2 * t[x * 2].sum * t[x].lzt + (len / 2) * t[x].lzt * t[x].lzt;
    t[x * 2 + 1].psum += 2 * t[x * 2 + 1].sum * t[x].lzt + (len - len / 2) * t[x].lzt * t[x].lzt;
    t[x * 2].sum += t[x].lzt * (len / 2);
    t[x * 2 + 1].sum += t[x].lzt * (len - len / 2);
    t[x * 2].lzt += t[x].lzt;
    t[x * 2 + 1].lzt += t[x].lzt;
    t[x].lzt = 0;
}

void build(int x, int l, int r)
{
    if (l == r) {
        t[x].sum = a[l], t[x].psum = a[l] * a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    pushup(x);
}

void modify(int x, int tgtl, int tgtr, int l, int r, double p)
{
    if (tgtl <= l && r <= tgtr) {
        t[x].lzt += p;
        t[x].psum += 2 * p * t[x].sum + (r - l + 1) * p * p;
        t[x].sum += (r - l + 1) * p;
        return;
    }

    pushdown(x, r - l + 1);
    int mid = (l + r) / 2;
    if (mid >= tgtl)
        modify(x * 2, tgtl, tgtr, l, mid, p);
    if (mid < tgtr)
        modify(x * 2 + 1, tgtl, tgtr, mid + 1, r, p);
    pushup(x);
}

double query111(int x, int tgtl, int tgtr, int l, int r)
{
    if (tgtl <= l && r <= tgtr)
        return t[x].sum;

    pushdown(x, r - l + 1);
    int mid = (l + r) / 2;
    double res = 0;
    if (mid >= tgtl)
        res += query111(x * 2, tgtl, tgtr, l, mid);
    if (mid < tgtr)
        res += query111(x * 2 + 1, tgtl, tgtr, mid + 1, r);
    return res;
}

double query222(int x, int tgtl, int tgtr, int l, int r)
{
    if (tgtl <= l && r <= tgtr)
        return t[x].psum;

    pushdown(x, r - l + 1);
    int mid = (l + r) / 2;
    double res = 0;
    if (mid >= tgtl)
        res += query222(x * 2, tgtl, tgtr, l, mid);
    if (mid < tgtr)
        res += query222(x * 2 + 1, tgtl, tgtr, mid + 1, r);
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    int op, x, y;
    double k;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            modify(1, x, y, 1, n, k);
        } else if (op == 2) {
            cin >> x >> y;
            // cout<<query111(1,x,y,1,n)<<endl;
            cout << fixed << setprecision(4) << (query111(1, x, y, 1, n) / (y - x + 1)) << "\n";
        } else {
            cin >> x >> y;
            double temp1 = query111(1, x, y, 1, n) / (y - x + 1);
            double temp2 = query222(1, x, y, 1, n) / (y - x + 1);
            double ans = temp2 - temp1 * temp1;
            cout << fixed << setprecision(4) << ans << "\n";
        }
    }

    return 0;
}