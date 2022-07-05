#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x7fffffff;

typedef pair<int, int> P;
map<int, map<int, int>> weight;
int dis[100001];

priority_queue<P, vector<P>, greater<int>> pq;

int main()
{
    // freopen("../../data/P4779_large.in", "r", stdin);
    // freopen("../../data/P4779_large-d.out", "w", stdout);
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        if (u == v) {
            continue;
        }
        if (weight.find(u) == weight.end() || weight[u].find(v) == weight[u].end() || w < weight[u][v]) {
            weight[u][v] = w;
        }
    }
    fill(dis + 1, dis + n + 1, INF);
    dis[s] = 0;
    pq.push(P(0, s));
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int x = p.second;
        if (dis[x] < p.first) {
            continue;
        }
        if (weight.find(x) == weight.end()) {
            continue;
        }
        for (auto it = weight[x].begin(); it != weight[x].end(); it++) {
            int y = it->first;
            if (dis[y] > dis[x] + it->second) {
                dis[y] = dis[x] + it->second;
                pq.push(P(dis[y], y));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}