#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 1e3 + 2;
ll G[MAX_N][MAX_N];
ll n, m;
ll INF = 0x3f3f3f3f3f3f3f3f;

int par[MAX_N];
ll bfs(int s, int t)
{
    ll flow[MAX_N];
    memset(par, 0, sizeof(par));
    flow[s] = INF;
    queue<int> Q;
    Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == t) {
            // Have found a path
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (G[u][i] > 0 && i != u && par[i] == 0) {
                Q.emplace(i);
                par[i] = u;
                flow[i] = min(flow[u], G[u][i]);
            }
        }
    }
    if (!par[t]) {
        return -1;
    } else {
        return flow[t];
    }
}

ll ek(int s, int t)
{
    ll maxflow = 0;
    while (true) {
        ll flow = bfs(s, t);
        if (flow == -1) {
            // Cannot find new argumenting path
            break;
        }
        int crt = t;
        while (crt != s) {
            // Generate reverse edge
            G[par[crt]][crt] -= flow;
            G[crt][par[crt]] += flow;
            crt = par[crt];
        }
        maxflow += flow;
    }
    return maxflow;
}

int main()
{
    // freopen("data/mf3.in", "r", stdin);
    int s, t;
    cin >> n >> m >> s >> t;
    int u, v;
    ll w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        // Add edge : You are supposed to add width when read multiple edge
        G[u][v] += w;
    }
    cout << ek(s, t) << endl;
    return 0;
}