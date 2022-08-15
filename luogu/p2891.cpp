#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_M = 5000;
constexpr int MAX_N = 600;
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

//食物：1~f,牛左：f+1~f+n,牛右：f+n+1~f+n+n,菜：f+n+n+1~f+n+n+d,起点：f+n+n+d+1，终点：f+n+n+d+2

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int n, f, d;
    cin >> n >> f >> d;
    s = f + n + n + d + 1;
    t = f + n + n + d + 2;
    for (int i = 1; i <= f; i++) {
        addEdge(s, i, 1);
        addEdge(i, s, 0);
    }
    for (int i = 1; i <= d; i++) {
        addEdge(f + n + n + i, t, 1);
        addEdge(t, f + n + n + i, 0);
    }
    int tf, td, tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tf >> td;
        for (int j = 1; j <= tf; j++) {
            cin >> tmp;
            addEdge(tmp, f + i, 1);
            addEdge(f + i, tmp, 0);
        }
        for (int j = 1; j <= td; j++) {
            cin >> tmp;
            addEdge(f + n + i, f + n + n + tmp, 1);
            addEdge(f + n + n + tmp, f + n + i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        addEdge(f + i, f + n + i, 1);
        addEdge(f + n + i, f + i, 0);
    }
    cout << dinic() << endl;
    return 0;
}