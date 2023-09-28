#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int n, m, a[N], fa[N];
vector<pair<int, int>> vc;
int calc(int x, int y)
{
    if (x > y) {
        return x - y;
    }
    return y - x;
}
int main()
{
    // freopen("end.in", "r", stdin);
    // freopen("end.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int ls, rs;
        cin >> ls >> rs;
        if (ls) {
            fa[ls] = i;
        }
        if (rs) {
            fa[rs] = i;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x, k;
        cin >> x >> k;
        a[x] = k;
        vc.push_back({ x, k });
    }
    while (m > 1) {
        memset(a, 0, sizeof(a));
        for (auto u : vc) {
            int x = u.first, k = u.second;
            if (x != 1) {
                x = fa[x];
            }
            if (a[x]) {
                a[x] = calc(a[x], k);
            } else {
                a[x] = k;
            }
        }
        vc.clear();
        m = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != 0) {
                vc.push_back({ i, a[i] }), ++m;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            cout << a[i] << endl;
            return 0;
        }
    }
    return 0;
}
