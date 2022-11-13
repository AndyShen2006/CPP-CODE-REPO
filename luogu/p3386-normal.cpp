#include <bits/stdc++.h>

using namespace std;
int G[1010][1010];
bool used[1010];
int match[1010];
int n, m, t;
bool found(int x)
{
    for (int i = 1; i <= m; i++) {
        if (G[x][i] && !used[i]) {
            used[i] = true;
            if (match[i] == 0 || found(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // freopen("data/p3386b.in", "r", stdin);
    cin >> n >> m >> t;
    int u, v;
    for (int i = 1; i <= t; i++) {
        cin >> u >> v;
        G[u][v] = 1;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        if (found(i)) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}