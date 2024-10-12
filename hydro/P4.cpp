#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_R = 10010;
constexpr int MAX_F = 5010;

// Graph
int head[MAX_F], cnt = 0;
struct Edge {
    int to, nxt;
} edges[MAX_R];

void init()
{
    for (auto& edge : edges) {
        edge.nxt = -1;
    }
    for (int& i : head) {
        i = -1;
    }
    cnt = 0;
}
void addEdge(int u, int v)
{
    edges[cnt].to = v;
    edges[cnt].nxt = head[u];
    head[u] = cnt++;
}

// Tarjan's Bipolar Connection Component Algorithm
int dfn[MAX_F], low[MAX_F], bccno[MAX_F], dfc, sum;
bool vis[MAX_F];
stack<int> stk;
map<int, set<int>> bcc;
int bcnt;
void tarjan(int u, int par)
{
    cerr << u << endl;
    low[u] = dfn[u] = ++dfc;
    stk.push(u);
    vis[u] = true;
    for (int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].to;
        if (i == (par ^ 1)) { // 双向边处理
            continue;
        }
        if (!dfn[v]) {
            tarjan(v, i);
            cerr << u << ' ' << v << endl;
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) { // 回退边
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        bcc[++bcnt].insert(u);
        bccno[u] = bcnt;
        while (stk.top() != u) {
            bcc[bcnt].insert(stk.top());
            bccno[stk.top()] = bcnt;
            vis[stk.top()] = false;
            stk.pop();
        }
        stk.pop();
    }
}

int deg[MAX_F];

int main()
{
    init();
    freopen("data/P4b.in", "r", stdin);
    int f, r;
    cin >> f >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        // cerr << u << "->" << v << endl;
        // cerr << v << "->" << u << endl;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= f; i++) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    // for (int i = 1; i <= f; i++) {
    //     for (int j = head[i]; ~j; j = edges[j].nxt) {
    //         cerr << i << ' ' << edges[j].to << ' ' << edges[j].nxt << endl;
    //     }
    // }
    // for (int i = 1; i <= f; i++) {
    //     cerr << i << endl;
    //     cerr << "dfn: " << dfn[i] << endl;
    //     cerr << "low: " << low[i] << endl;
    // }
    // for (const auto& pr : bcc) {
    //     cerr << pr.first << ": ";
    //     for (auto it : pr.second) {
    //         cerr << it << ' ';
    //     }
    //     cerr << endl;
    // }
    // for (int i = 1; i <= f; i++) {
    //     cerr << i << ':' << bccno[i] << endl;
    // }
    for (int i = 1; i <= f; i++) {
        for (int j = head[i]; ~j; j = edges[j].nxt) {
            int v = edges[j].to;
            // cerr << i << ' ' << v << endl;
            if (bccno[i] == bccno[v]) {
                continue;
            }
            deg[bccno[v]]++;
        }
    }
    for (int i = 1; i <= f; i++) {
        cerr << i << ':' << deg[i] << endl;
    }
    int sum = 0;
    for (int i = 1; i <= f; i++) {
        if (deg[i] == 1) {
            sum++;
        }
    }
    cout << ((sum + 1) >> 1) << endl;
    return 0;
}