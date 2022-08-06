#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m, s, t;
constexpr int MAX_N = 5010;
constexpr int MAX_M = 50010;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

//链式前向星
struct Edge {
    int to, next;
    ll flow, cost;
} edges[MAX_M];
int head[MAX_N], cnt;

void init()
{
    for (auto& it : edges) {
        it.next = -1;
    }
    for (int& it : head) {
        it = -1;
    }
}

void addEdge(int u, int v, ll flow, ll cost)
{
    edges[cnt].to = v;
    edges[cnt].cost = cost;
    edges[cnt].flow = flow;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}
// SPFA
int par[MAX_N];
ll dis[MAX_N];
ll flow[MAX_N];
bool inq[MAX_N];
bool spfa()
{

    memset(par, 0, sizeof(par));
    memset(dis, 0x3f, sizeof(dis));
    flow[s] = INF;
    dis[s] = 0;
    queue<int> Q;
    Q.emplace(s);
    inq[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        if (u == t) {
            break;
        }
        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[u].flow > 0 && i != u && par[i] == 0 && dis[u] + edges[i].cost < dis[v]) {
                dis[v] = dis[u] + edges[i].cost;
                par[v] = u;
                flow[v] = min(flow[u], edges[i].flow);
                if (!inq[v]) {
                    Q.emplace(v);
                    inq[v] = true;
                }
            }
        }
    }
    return par[t];
}

// MCMF(Minimum Cost Maximum FLow)(Like Edmonds-Karp)

ll maxflow, mincost;
void mcmf()
{
    while (spfa()) {
        int x = t;
        maxflow += flow[t];
        mincost += dis[t];
        int i;
        while (x != s) {
            i = par[x];
            edges[i].flow -= flow[t];
            edges[i ^ 1].flow += flow[t];
            x = edges[i ^ 1].to;
        }
    }
}

int main()
{
    freopen("data/mcmf1.in", "r", stdin);
    init();
    cin >> n >> m >> s >> t;
    int u, v;
    ll f, c;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> f >> c;
        addEdge(u, v, f, c);
        addEdge(u, v, 0, -c);
    }
    mcmf();
    cout << maxflow << ' ' << mincost << endl;
    return 0;
}