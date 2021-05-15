#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 1 << 30;

vector<int> G[maxn];
int n, d[maxn];
int cnt;

void bfs(int s)
{
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    int u;
    while (!Q.empty()) {
        u = Q.front(), Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int e = G[u][i];
            if (d[e] == INF) {
                d[e] = d[u] + 1;
                Q.push(e);
            }
        }
    }
}

int main()
{
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    bfs(G[1].front());
    int maxv = 0;
    int tgt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            continue;
        if (maxv < d[i]) { //Update
            maxv = d[i];
            tgt = i;
        }
    }
    bfs(tgt);
    maxv = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF)
            continue;
        maxv = max(maxv, d[i]);
    }
    printf("%d\n", maxv);
    return 0;
}
