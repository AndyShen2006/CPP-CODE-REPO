#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
vector<int> G[110];
queue<P> q; // Node,depth
int width[110];
int depth[110];
int par[110];
bool hasFound[110];
int maxdep = 0;

int lca(int x, int y)
{
    int xdep = 0, ydep = 0;
    while (depth[x] > depth[y]) {
        x = par[x];
        xdep++;
    }
    while (depth[x] < depth[y]) {
        y = par[y];
        ydep++;
    }
    while (x != y) {
        x = par[x];
        xdep++;
        y = par[y];
        ydep++;
    }
    return xdep * 2 + ydep;
}

int main()
{
    // freopen("data/p3384.in", "r", stdin);
    int n;
    cin >> n;
    int u, v, x, y;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> x >> y;
    q.push(P(1, 1));
    hasFound[1] = true;
    while (!q.empty()) {
        P t = q.front();
        q.pop();
        depth[t.first] = t.second;
        width[t.second]++;
        for (auto it : G[t.first]) {
            if (!hasFound[it]) {
                par[it] = t.first;
                hasFound[it] = true;
                q.push(make_pair(it, t.second + 1));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        maxdep = max(maxdep, depth[i]);
    }
    cout << maxdep << endl;
    int maxwid = 0;
    for (int i = 0; i <= maxdep; i++) {
        maxwid = max(maxwid, width[i]);
    }
    cout << maxwid << endl;
    cout << lca(x, y) << endl;
    return 0;
}