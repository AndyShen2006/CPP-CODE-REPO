#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 40010;
constexpr int MAX_M = 600010;
//链式前向星
struct Edge {
    int to, next;
    ll wid;
} edges[MAX_M];
int head[MAX_N];
int cnt;
void init()
{
    for (auto& edge : edges) {
        edge.next = -1;
    }
    for (int& i : head) {
        i = -1;
    }
}
void addEdge(int u, int v, ll w)
{
    edges[cnt].to = v;
    edges[cnt].wid = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}
// Dinic算法
int n, m, s, t;
int depth[MAX_N];
int nxt[MAX_N];
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
bool bfs()
{
    queue<int> Q;
    Q.emplace(s);
    memset(depth, 0, sizeof(depth)); //***
    depth[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; ~i; i = edges[i].next) {
            if (edges[i].wid > 0 && !depth[edges[i].to]) { //***
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
ll dfs(int x, ll flow)
{
    if (x == t) {
        return flow;
    }
    ll flowsum = 0;
    for (int& i = nxt[x]; ~i; i = edges[i].next) {
        // nxt[x] = i;***
        if (edges[i].wid > 0 && depth[edges[i].to] == depth[x] + 1) { //***
            ll tmp = dfs(edges[i].to, min(flow - flowsum, edges[i].wid));
            flowsum += tmp;
            edges[i].wid -= tmp;
            edges[i ^ 1].wid += tmp;
            if (flow == flowsum) {
                break;
            }
        }
    }
    if (!flowsum) {
        depth[x] = 0;
    }
    return flowsum;
}

ll dinic()
{
    ll ans = 0, tmp;
    while (bfs()) {
        for (int i = 0; i < MAX_N; i++) {
            nxt[i] = head[i];
        }
        tmp = dfs(s, INF);
        ans += tmp;
    }
    return ans;
}

int main()
{
    init();
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/mf1.in", "r", stdin);
    cin >> n >> m >> s >> t;
    int u, v;
    ll w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, 0); //***
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = head[i]; ~j; j = edges[j].next) {
    //         cout << i << ' ' << edges[j].to << ' ' << edges[j].wid << endl;
    //     }
    // }
    cout << dinic() << endl;
    return 0;
}