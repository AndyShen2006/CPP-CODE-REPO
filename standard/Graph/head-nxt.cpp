#include <bits/stdc++.h>

using namespace std;
constexpr int NUM = 1000000;
int head[NUM], cnt;
struct Edge {
    int to, next, wid;
} edges[NUM];
void init()
{
    for (auto& edge : edges) {
        edge.next = -1;
    }
    for (int& i : head) {
        i = -1;
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
    freopen("data/graph1.in", "r", stdin);
    init();
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; ~j; j = edges[j].next) {
            cout << i << ' ' << edges[j].to << ' ' << edges[j].wid << endl;
        }
    }
    return 0;
}