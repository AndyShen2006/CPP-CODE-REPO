#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 1001;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll G[MAX_N][MAX_N];
int n, m, s, t;
bool vis[MAX_N];

ll dfs(int x, ll flow)
{
    vis[x] = true;
    if (x == t) {
        return flow;
    }
    for (int i = 1; i <= n; i++) {
        if (G[x][i] > 0 && !vis[i]) {
            ll f = dfs(i, min(flow, G[x][i]));
            if (f > 0) {
                G[x][i] -= f;
                G[i][x] += f;
                return f;
            }
        }
    }
    return 0;
}

ll ford()
{
    ll ans = 0, tmp;
    do {
        memset(vis, 0, sizeof(vis));
        tmp = dfs(s, INF);
        ans += tmp;
    } while (tmp);
    return ans;
}

int main()
{
    // freopen("data/mf3.in", "r", stdin);
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u][v] += w;
    }
    cout << ford() << endl;
    return 0;
}