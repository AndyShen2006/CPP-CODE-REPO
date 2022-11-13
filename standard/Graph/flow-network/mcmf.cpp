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
queue<int> Q;
bool spfa()
{
    Q.push(s);
    inq[s] = true;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    memset(flow, 0x3f, sizeof(flow));
    memset(par, 0, sizeof(par));
    par[s] = s;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        if (u == t) {
            break;
        }
        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (edges[i].flow > 0 && dis[u] + edges[i].cost < dis[v]) {
                dis[v] = dis[u] + edges[i].cost;
                flow[v] = min(flow[u], edges[i].flow);
                par[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    Q.emplace(v);
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
        cout << par[t] << endl;
        mincost += dis[t];
        while (x != s) {
            edges[x].flow -= flow[t];
            edges[x ^ 1].flow += flow[t];
            x = par[x];
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
        cin >> u >> v >> c >> f;
        addEdge(u, v, f, c);
        addEdge(v, u, 0, -c);
    }
    spfa();
    mcmf();
    cout << maxflow << ' ' << mincost << endl;
    return 0;
}