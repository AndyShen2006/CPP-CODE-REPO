#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

constexpr int MAX_N = 100010, MAX_M = 200010;

int dis[MAX_N];
int head[MAX_N], cnt;
struct Edge {
    int to, next, wid;
} edges[MAX_M];
void init(int n, int m)
{
    for (int i = 1; i <= m + 10; i++) {
        edges[i].next = -1;
    }
    for (int i = 1; i <= n + 10; i++) {
        head[i] = -1;
    }
    cnt = 0;
}
void addEdge(int u, int v, int w)
{
    edges[cnt].to = v;
    edges[cnt].wid = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    init(n, m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto p = q.top();
        const int& u = p.second;
        q.pop();
        if (p.first > dis[u]) {
            continue;
        }
        for (int i = head[u]; ~i; i = edges[i].next) {
            const int& v = edges[i].to;
            if (dis[u] + edges[i].wid < dis[v]) {
                dis[v] = dis[u] + edges[i].wid;
                q.emplace(dis[v], v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}
