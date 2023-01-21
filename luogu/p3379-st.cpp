#include <bits/stdc++.h>

using namespace std;

vector<int> T[500010];
int f[500010][25], dep[500010];

void dfs(int x, int par, int dep)
{
    f[x][0] = par;
    dep[x] = dep;
    for (auto it : T[x]) {
        if (it == par) {
            continue;
        }
        dfs(it, x, dep + 1);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        x = f[x][static_cast<int>(log2(dep[x] - dep[y]))];
    }
    if (x == y) {
        return x;
    }
    for (int k = log2(dep[x]) - 1; k >= 0; --k) {
        if (f[x][k] != f[y][k]) {
            x = f[x][k];
            y = f[y][k];
        }
    }
    return f[x][0];
}

int main()
{
    // freopen("data/p3379.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    int x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        T[x].emplace_back(y);
        T[y].emplace_back(x);
    }
    dfs(s, s, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= log2(n); j++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}