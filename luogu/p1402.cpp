#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_M = 3000;
constexpr int MAX_N = 500;
struct Edge {
    int to, nxt, wid;
} edges[MAX_M];
int head[MAX_N], cnt;
void init()
{
    for (int& it : head) {
        it = -1;
    }
    for (auto& it : edges) {
        it.nxt = -1;
    }
}
void addEdge(int u, int v, int w)
{
    edges[cnt].to = v;
    edges[cnt].wid = w;
    edges[cnt].nxt = head[u];
    head[u] = cnt++;
}
int s, t;
int depth[MAX_N], nxt[MAX_N];
bool bfs()
{
    queue<int> Q;
    memset(depth, 0, sizeof(depth));
    depth[s] = 1;
    Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; ~i; i = edges[i].nxt) {
            if (edges[i].wid > 0 && !depth[edges[i].to]) {
                depth[edges[i].to] = depth[u] + 1;
                if (edges[i].to == t) {
                    return true;
                }
                Q.emplace(edges[i].to);
            }
        }
    }
    return false;
}
int dfs(int x, int flow)
{
    if (x == t) {
        return flow;
    }
    int flowsum = 0, tmp;
    for (int i = nxt[x]; ~i; i = edges[i].nxt) {
        nxt[x] = i;
        if (edges[i].wid > 0 && depth[edges[i].to] == depth[x] + 1) {
            tmp = dfs(edges[i].to, min(edges[i].wid, flow - flowsum));
            edges[i].wid -= tmp;
            edges[i ^ 1].wid += tmp;
            flowsum += tmp;
            if (flowsum == flow) {
                break;
            }
        }
    }
    if (!flowsum) {
        depth[x] = 0;
    }
    return flowsum;
}

int dinic()
{
    int ans = 0, tmp;
    while (bfs()) {
        for (int i = 0; i < MAX_N; i++) {
            nxt[i] = head[i];
        }
        tmp = dfs(s, 0x3f3f3f3f);
        ans += tmp;
    }
    return ans;
}

//房间：1~p,人左：p+1~p+n,人右：p+n+1~p+n+n,菜：p+n+n+1~p+n+n+q,起点：p+n+n+q+1，终点：p+n+n+q+2

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int n, p, q;
    cin >> n >> p >> q;
    s = p + n + n + q + 1;
    t = p + n + n + q + 2;
    for (int i = 1; i <= p; i++) {
        addEdge(s, i, 1);
        addEdge(i, s, 0);
    }
    for (int i = 1; i <= q; i++) {
        addEdge(p + n + n + i, t, 1);
        addEdge(t, p + n + n + i, 0);
    }
    bool like;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            cin >> like;
            if (like) {
                addEdge(j, p + i, 1);
                addEdge(p + i, j, 0);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        addEdge(p + i, p + n + i, 1);
        addEdge(p + n + i, p + i, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= q; j++) {
            cin >> like;
            if (like) {
                addEdge(p + n + i, p + n + n + j, 1);
                addEdge(p + n + n + j, p + n + i, 0);
            }
        }
    }
    cout << dinic() << endl;
    return 0;
}