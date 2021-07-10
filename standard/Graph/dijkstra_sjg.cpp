#include <bits/stdc++.h>
using namespace std;

#define NUM 100001
#define INF 0x7fffffff
#define LOCAL 1

int n, m, s;
unordered_map<int, unordered_map<int, int>> c;

int dist[NUM]; // 0 not used
bool S[NUM];

struct MyGreater {
    bool operator()(int& idX, int& idY)
    {
        return dist[idX] > dist[idY];
    }
};
priority_queue<int, vector<int>, MyGreater> pq;

void dijkstra(int s)
{
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        S[i] = false;
    }
    for (auto it : c[s]) {
        int t = it.first;
        int w = it.second;
        dist[t] = w;
    }
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        if (S[u])
            continue; // u already in S
        S[u] = true; // add u to S
        if (c.find(u) != c.end()) {
            for (auto it : c[u]) { // all u -> v [w]
                int v = it.first;
                int w = it.second;
                dist[v] = min(dist[v], dist[u] + w); // update dist[v] by u
                pq.push(v); // push all v
            }
        }
    }
}

int main()
{
#if LOCAL
    freopen("../data/dijkstra2.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &s);
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (c.find(u) == c.end() || c[u].find(v) == c[u].end() || w < c[u][v]) {
            c[u][v] = w;
        }
    }
    dijkstra(s);
    for (int j = 1; j <= n; ++j) {
        printf("%d ", dist[j]);
    }
    return 0;
}