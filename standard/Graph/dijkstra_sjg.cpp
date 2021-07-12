#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
typedef pair<int, int> P;
map<int, map<int, int>> weight;
int dis[100001];

int n, m;

priority_queue<P, vector<P>, greater<>> pq;

void dijkstra(int s)
{
    fill(dis + 1, dis + 1 + n, INF);
    dis[s] = 0;
    pq.push(P(0, s));
    while (!pq.empty()) {
        P element = pq.top();
        pq.pop();
        int u = element.second;
        if (dis[u] < element.first)
            continue;
        if (weight.find(u) == weight.end()) {
            continue;
        }
        for (auto it = weight.at(u).begin(); it != weight.at(u).end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push(P(dis[v], v));
            }
        }
    }
}

int main()
{
    int s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        weight[u][v] = w;
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
    return 0;
}