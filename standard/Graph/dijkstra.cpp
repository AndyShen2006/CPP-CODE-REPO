#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x7fffffff;

map<int, map<int, int>> weight;
int dis[100001];
bool vis[100001];
struct GreaterFunctor {
    inline auto operator()(int& x, int& y) -> bool
    {
        return dis[x] > dis[y];
    }
};
priority_queue<int, vector<int>, GreaterFunctor> pq;

auto main() -> int
{
    //freopen("../data/dijkstra2.in", "r", stdin);
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        //        if (u == v) {
        //            weight[u][v] = 0;
        //            continue;
        //        }
        if (weight.find(u) == weight.end() || weight[u].find(v) == weight[u].end() || w < weight[u][v]) {
            weight[u][v] = w;
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i] = (i == s ? 0 : INF);
    }
    for (map<int, int>::iterator it = weight[s].begin(); it != weight[s].end(); it++) {
        dis[it->first] = it->second;
    }
    //s add 1
    pq.push(s);
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (vis[x]) {
            continue;
        }
        //printf("pop queue top %d\n", x);
        vis[x] = true;
        if (weight.find(x) != weight.end()) {
            for (map<int, int>::iterator it = weight[x].begin(); it != weight[x].end(); it++) {
                int y = it->first;
                int m = it->second;
                if (dis[x] + m < dis[y]) {
                    //printf("Update dis[%d] from %d to %d\n", y, dis[y], dis[x] + m);
                }
                dis[y] = min(dis[y], dis[x] + m);
                //printf("push %d to queue\n", y);
                pq.push(y);
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        int x = s, m = INF;
        for (int y = 1; y <= n; y++) {
            if (!vis[y] && dis[y] < m) {
                m = dis[x = y];
            }
        }
        vis[x] = 1;
        for (int y = 1; y <= n; y++) {
            if (weight.find(x) != weight.end() && weight[x].find(y) != weight[x].end()) {
                dis[y] = min(dis[y], dis[x] + weight[x][y]);
            }
        }
    }
    */
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}