#include <bits/stdc++.h>

using namespace std;

struct Node {
    int r, c, st;
};

int f[110][110][110]; // 从s,t出发到i,j走严格大于路径经过k格所获得的最大权值
int g[110][110][110]; // 从s,t出发到i,j走严格小于路径经过k格所获得的最大权值
int a[110][110];

int main()
{
    freopen("pick_up.in", "r", stdin);
    freopen("pick_up.out", "w", stdout);
    int n, m, s, t, d;
    cin >> n >> m >> s >> t >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    queue<Node> Q;
    Q.push({ s, t, 0 });
    while (!Q.empty()) {
        auto cp = Q.front();
        Q.pop();
        if (cp.r - 1 > 0 && cp.c - 1 > 0) {
            if (a[cp.r][cp.c] < a[cp.r - 1][cp.c - 1] && f[cp.r - 1][cp.c - 1][cp.st + 1] < f[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c - 1]) {
                f[cp.r - 1][cp.c - 1][cp.st + 1] = f[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c - 1];
                Q.push({ cp.r - 1, cp.c - 1, cp.st + 1 });
            }
        }
        if (cp.r - 1 > 0 && cp.c + 1 <= m) {
            if (a[cp.r][cp.c] < a[cp.r - 1][cp.c + 1] && f[cp.r - 1][cp.c + 1][cp.st + 1] < f[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c + 1]) {
                f[cp.r - 1][cp.c + 1][cp.st + 1] = f[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c + 1];
                Q.push({ cp.r - 1, cp.c + 1, cp.st + 1 });
            }
        }
        if (cp.r + 1 <= n && cp.c - 1 > 0) {
            if (a[cp.r][cp.c] < a[cp.r + 1][cp.c - 1] && f[cp.r + 1][cp.c - 1][cp.st + 1] < f[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c - 1]) {
                f[cp.r + 1][cp.c - 1][cp.st + 1] = f[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c - 1];
                Q.push({ cp.r + 1, cp.c - 1, cp.st + 1 });
            }
        }
        if (cp.r + 1 <= n && cp.c + 1 <= m) {
            if (a[cp.r][cp.c] < a[cp.r + 1][cp.c + 1] && f[cp.r + 1][cp.c + 1][cp.st + 1] < f[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c + 1]) {
                f[cp.r + 1][cp.c + 1][cp.st + 1] = f[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c + 1];
                Q.push({ cp.r + 1, cp.c + 1, cp.st + 1 });
            }
        }
    }
    Q.push({ s, t, 0 });
    while (!Q.empty()) {
        auto cp = Q.front();
        Q.pop();
        if (cp.r - 1 > 0 && cp.c - 1 > 0) {
            if (a[cp.r][cp.c] > a[cp.r - 1][cp.c - 1] && g[cp.r - 1][cp.c - 1][cp.st + 1] < g[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c - 1]) {
                g[cp.r - 1][cp.c - 1][cp.st + 1] = g[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c - 1];
                Q.push({ cp.r - 1, cp.c - 1, cp.st + 1 });
            }
        }
        if (cp.r - 1 > 0 && cp.c + 1 <= m) {
            if (a[cp.r][cp.c] > a[cp.r - 1][cp.c + 1] && g[cp.r - 1][cp.c + 1][cp.st + 1] < g[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c + 1]) {
                g[cp.r - 1][cp.c + 1][cp.st + 1] = g[cp.r][cp.c][cp.st] + a[cp.r - 1][cp.c + 1];
                Q.push({ cp.r - 1, cp.c + 1, cp.st + 1 });
            }
        }
        if (cp.r + 1 <= n && cp.c - 1 > 0) {
            if (a[cp.r][cp.c] > a[cp.r + 1][cp.c - 1] && g[cp.r + 1][cp.c - 1][cp.st + 1] < g[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c - 1]) {
                g[cp.r + 1][cp.c - 1][cp.st + 1] = g[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c - 1];
                Q.push({ cp.r + 1, cp.c - 1, cp.st + 1 });
            }
        }
        if (cp.r + 1 <= n && cp.c + 1 <= m) {
            if (a[cp.r][cp.c] > a[cp.r + 1][cp.c + 1] && g[cp.r + 1][cp.c + 1][cp.st + 1] < g[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c + 1]) {
                g[cp.r + 1][cp.c + 1][cp.st + 1] = g[cp.r][cp.c][cp.st] + a[cp.r + 1][cp.c + 1];
                Q.push({ cp.r + 1, cp.c + 1, cp.st + 1 });
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= m; l++) {
                    cout << k << ' ' << l << ' ' << j << ' ' << i - j << endl;
                    cout << f[k][l][j] << ' ' << g[k][l][i - j] << endl;
                    // if (f[k][l][j] != 0 && g[k][l][i - j] != 0) {
                    ans = max(f[k][l][j], g[k][l][i - j]);
                    // }
                }
            }
        }
    }
    cout << ans << endl;
    for (auto it : f[4][4]) {
        cout << it << ' ';
    }
    cout << endl;
    for (auto it : g[4][4]) {
        cout << it << ' ';
    }
    return 0;
}