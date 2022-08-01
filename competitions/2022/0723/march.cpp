#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
constexpr int N = 10000;

vector<P> G[N];
vector<P> nG[N];
ll dis[N];
ll nDis[N];
bool isFind[N];
priority_queue<P, vector<P>, greater<P>> pq;
constexpr ll INF = 0x3f3f3f3f3f3f;

int main()
{
    // freopen("data/march1.in", "r", stdin);
    // freopen("data/march1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int from, to, value;
    for (int i = 1; i <= m; i++) {
        cin >> from >> to >> value;
        G[from].push_back(P(to, value));
        nG[to].push_back(P(from, value));
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(isFind, 0, sizeof(isFind));
    dis[1] = 0;
    pq.push(P(0, 1));
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (isFind[p.second])
            continue;
        isFind[p.second] = true;
        for (auto it : G[p.second]) {
            // Relax
            if (dis[p.second] + it.second < dis[it.first]) {
                dis[it.first] = dis[p.second] + it.second;
                pq.push(P(dis[it.first], it.first));
            }
        }
    }
    memset(nDis, 0x3f, sizeof(nDis));
    memset(isFind, 0, sizeof(isFind));
    nDis[1] = 0;
    pq.push(P(0, 1));
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (isFind[p.second])
            continue;
        isFind[p.second] = true;
        for (auto it : nG[p.second]) {
            // Relax
            if (nDis[p.second] + it.second < nDis[it.first]) {
                nDis[it.first] = nDis[p.second] + it.second;
                pq.push(P(nDis[it.first], it.first));
            }
        }
    }
    ll T, u, v, ans;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> u >> v;
        ans = nDis[u] + dis[v];
        cout << ((ans > INF) ? -1 : ans) << endl;
    }
    return 0;
}