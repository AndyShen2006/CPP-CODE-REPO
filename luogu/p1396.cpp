#include <bits/stdc++.h>

using namespace std;

// The following is define section
struct edge {
    int from, to, val;
    bool operator>(const edge& b) const
    {
        return this->val > b.val;
    }
    bool operator<(const edge& b) const
    {
        return this->val < b.val;
    }
    edge() = default;
    edge(int f, int t, int v)
    {
        from = f;
        to = t;
        val = v;
    }
};

constexpr int N = 10010;
vector<edge> E;
typedef pair<int, int> P;
vector<P> T[N];
int n, m, s, t;

// The following is Union-Find-Set
int par[N];
void init()
{
    for (int i = 0; i < N; i++) {
        par[i] = i;
    }
}
int findPar(int node)
{
    if (par[node] == node) {
        return node;
    } else {
        return par[node] = findPar(par[node]);
    }
}
void unionNode(int u, int v)
{
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu == pv) {
        return;
    } else {
        par[pu] = pv;
    }
}

bool samePar(int u, int v)
{
    return findPar(u) == findPar(v);
}
// Depth-Find-Search
bool isFind[N]; // Has Find->True;Has't Find->False
void dfs(int node, int maxedge)
{
    if (isFind[node]) {
        return;
    }
    isFind[node] = true;
    if (node == t) {
        cout << maxedge << endl;
        return;
    }
    for (auto it : T[node]) {
        dfs(it.first, max(it.second, maxedge));
    }
}
// Main Function
int main()
{
    // freopen("data/p1396d.in", "r", stdin);
    //    Initalization and Input
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        E.push_back(edge(u, v, w));
    }
    // Kruskal's Algorithm
    sort(E.begin(), E.end());
    // for (auto it : E) {
    //     printf("%d %d %d\n", it.from, it.to, it.val);
    // }
    // exit(0);
    init();
    for (auto it : E) {
        if (!samePar(it.from, it.to)) {
            // Add edge
            unionNode(it.from, it.to);
            T[it.from].push_back(P(it.to, it.val));
            T[it.to].push_back(P(it.from, it.val));
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (auto it : T[i]) {
    //         printf("%d %d %d\n", i, it.first, it.second);
    //     }
    // }
    // Depth-first-Search
    dfs(s, 0);
    return 0;
}