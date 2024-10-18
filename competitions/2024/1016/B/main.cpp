#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr int MAX_N = 510, MAX_M = 1e5 + 10;
int n, m;
int a[MAX_N];
set<ll> as;
struct Edge {
    int u, v;
    ll w;
} edges[MAX_M];

vector<pair<int, ll>> G[MAX_N];
ll dis[MAX_N];

void genGraph(ll ma)
{
    // cerr << ma << endl;
    // Clear Graph
    for (auto& it : G) {
        it.clear();
    }
    // Clear Distances
    memset(dis, 0x3f, sizeof(dis));
    // Regenerate Graph
    for (int i = 1; i <= m; i++) {
        // cerr << a[edges[i].v] << endl;
        if (a[edges[i].v] <= ma) {
            G[edges[i].u].emplace_back(edges[i].v, edges[i].w);
            // cerr << edges[i].u << ' ' << edges[i].v << ' ' << edges[i].w << endl;
        }
        if (a[edges[i].u] <= ma) {
            G[edges[i].v].emplace_back(edges[i].u, edges[i].w);
        }
    }
}

void dijkstra()
{
    // __gnu_pbds::priority_queue<pair<ll, int>, greater<pair<ll, int>>, __gnu_pbds::pairing_heap_tag> q;
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, 1);
    // q.emplace(0, s);
    while (!q.empty()) {
        auto p = q.top();
        const int& u = p.second;
        q.pop();
        if (p.first > dis[u]) {
            continue;
        }
        for (auto it : G[u]) {
            const ll& v = it.first;
            if (dis[u] + it.second < dis[v]) {
                dis[v] = dis[u] + it.second;
                q.emplace(dis[v], v);
            }
        }
    }
}

int main()
{
    // freopen("data/b2.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        as.insert(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }
    ll ans = INF;
    for (auto it : as) {
        genGraph(it);
        dijkstra();
        ans = min(ans, dis[n] + it);
        // cerr << ans << ' ' << dis[n] << ' ' << it << endl;
    }
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}