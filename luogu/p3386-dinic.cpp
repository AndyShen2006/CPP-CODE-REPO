#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int MAX_N = 1010;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll G[MAX_N][MAX_N];
int depth[MAX_N];
int nxt[MAX_N];
int n, m, e, s, t;
bool bfs()
{
    queue<int> Q;
    Q.emplace(s);
    memset(depth, 0, sizeof(depth));
    depth[s] = 1;
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        for (int i = 1; i <= n + m + 2; i++) {
            if (G[u][i] && !depth[i]) {
                depth[i] = depth[u] + 1;
                if (i == t) {
                    return true;
                }
                Q.emplace(i);
            }
        }
    }
    return false;
}

ll dfs(int x, ll flow)
{
    if (x == t) {
        return flow;
    }
    ll flowsum = 0;
    for (int i = nxt[x]; i <= n + m + 2; i++) {
        nxt[x] = i;
        if (G[x][i] > 0 && depth[i] == depth[x] + 1) {
            ll tmp = dfs(i, min(flow - flowsum, G[x][i]));
            if (tmp) {
                G[x][i] -= tmp;
                G[i][x] += tmp;
                flowsum += tmp;
                if (flowsum == flow) {
                    break;
                }
            }
        }
    }
    if (!flowsum) {
        depth[x] = 0;
    }
    return flowsum;
}

ll dinic()
{
    ll ans = 0, tmp;
    while (bfs()) {
        fill(nxt + 1, nxt + n + m + 3, 1);
        tmp = dfs(s, INF);
        ans += tmp;
    }
    return ans;
}

int main()
{
    cin >> n >> m >> e;
    int u, v;
    // Input graph
    for (int i = 1; i <= e; i++) {
        cin >> u >> v;
        G[u][n + v] = 1;
    }
    s = n + m + 1;
    t = n + m + 2;
    // Finish generating graph
    for (int i = 1; i <= n; i++) {
        G[s][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        G[n + i][t] = 1;
    }
    // Dinic argumenting algorithm
    cout << dinic() << endl;
    return 0;
}