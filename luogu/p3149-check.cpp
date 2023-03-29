#include <bits/stdc++.h>
using namespace std;
#define lb(x) x & -x
const int N = 4e5;
int b[N], a[N], n, cnt, m, lst;
long long c[N], p[N], ans;
void change(int x)
{
    while (x <= cnt)
        c[x]++, x += lb(x);
}
int ask(int x)
{
    int res = 0;
    while (x)
        res += c[x], x -= lb(x);
    return res;
}
signed main()
{
    freopen("data/p3179b.in", "r", stdin);
    freopen("data/p3149.chk", "w", stdout);
    freopen("data/p3149.log", "w", stderr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    cnt = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = n, k; i; i--) {
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
        k = ask(a[i] - 1);
        ans += k, p[a[i]] += k;
        change(a[i]);
    }
    cout << ans << endl;
    for (int i = 1, q; i <= m; i++) {
        cin >> q;
        while (a[q] > lst)
            lst++, ans -= p[lst];
        cout << ans << endl;
    }
    return 0;
}