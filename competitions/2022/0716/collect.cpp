#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, w;
    double x;
};

vector<Edge> G[30001];
queue<int> Q;

int main()
{
    freopen("data/collect.in", "r", stdin);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    int u, v, w;
    double x;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w >> x;
        G[u].emplace_back(Edge { v, w, x });
    }
    int s;
    cin >> s;
    Q.push(s);
    while (!Q.empty()) {
        int Node = Q.front();
        Q.pop();
        cout << Node << endl;
        for (auto& it : G[Node]) {
            ans += it.w;
            it.w = (it.w * it.x);
            Q.push(it.to);
        }
    }
    cout << ans << endl;
    return 0;
}