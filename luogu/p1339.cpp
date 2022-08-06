#include <bits/stdc++.h>

using namespace std;

int dis[2510];
vector<pair<int, int>> G[2510];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].emplace_back(make_pair(v, w));
        G[v].emplace_back(make_pair(u, w));
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    Q.emplace(make_pair(0, s));
    while (!Q.empty()) {
        auto u = Q.top();
        Q.pop();
        if (dis[u.second] < u.first) {
            continue;
        }
        for (auto it : G[u.second]) {
            if (dis[it.first] > dis[u.second] + it.second) {
                dis[it.first] = dis[u.second] + it.second;
                Q.emplace(make_pair(dis[it.first], it.first));
            }
        }
    }
    cout << dis[t] << endl;
    return 0;
}