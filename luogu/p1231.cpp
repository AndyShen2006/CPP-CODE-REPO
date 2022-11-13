#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 40010;
constexpr int MAX_M = 600010;
//链式前向星
struct Edge {
    int to, next, wid;
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
void addEdge(int u, int v, int w)
{
    edges[cnt].to = v;
    edges[cnt].wid = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}
// Dinic算法
int n, s, t;
int depth[MAX_N];
int nxt[MAX_N];
constexpr int INF = 0x3f3f3f3f;
bool bfs()
{
    queue<int> Q;
    Q.emplace(s);
    memset(depth, 0, sizeof(depth));
    depth[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; ~i; i = edges[i].next) {
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
    int flowsum = 0;
    for (int& i = nxt[x]; ~i; i = edges[i].next) {
        // nxt[x] = i;
        if (edges[i].wid > 0 && depth[edges[i].to] == depth[x] + 1) {
            int tmp = dfs(edges[i].to, min(flow - flowsum, edges[i].wid));
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

int dinic()
{
    int ans = 0, tmp;
    while (bfs()) {
        for (int i = 0; i < MAX_N; i++) {
            nxt[i] = head[i];
        }
        tmp = dfs(s, INF);
        ans += tmp;
    }
    return ans;
}

// 1~a->书（左点），a+1~a+b->练习册，a+b+1~a+b+c->答案，a+b+c+1~a+b+c+a->书的拆点（右点），a+b+c+a+1->源点，a+b+c+a+2->汇点
//三步：1、将所有书全部拆点拆掉 2.练习册全部连书的左点，书的右点全部连答案3.跑网络流
int main()
{
    // freopen("data/p1231c.in", "r", stdin);
    // freopen("data/p1231a.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        addEdge(i, a + b + c + i, 1);
        addEdge(a + b + c + i, i, 0);
    }
    int m1;
    cin >> m1;
    int x, y;
    for (int i = 1; i <= m1; i++) {
        cin >> x >> y;
        addEdge(a + y, x, 1);
        addEdge(x, a + y, 0);
    }
    int m2;
    cin >> m2;
    for (int i = 1; i <= m2; i++) {
        cin >> x >> y;
        addEdge(a + b + c + x, a + b + y, 1);
        addEdge(a + b + y, a + b + c + x, 0);
    }
    n = a + b + c + a + 2;
    s = a + b + c + a + 1;
    t = a + b + c + a + 2;
    for (int i = 1; i <= b; i++) {
        addEdge(s, a + i, 1);
        addEdge(a + i, s, 0);
    }
    for (int i = 1; i <= c; i++) {
        addEdge(a + b + i, t, 1);
        addEdge(t, a + b + i, 0);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = head[i]; ~j; j = edges[j].next) {
    //         cout << i << ' ' << edges[j].to << ' ' << edges[j].wid << endl;
    //     }
    // }
    cout << dinic() << endl;
    return 0;
}