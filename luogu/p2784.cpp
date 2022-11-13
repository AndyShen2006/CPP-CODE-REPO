#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5010;
typedef pair<int, double> P;
typedef pair<double, int> nP;
vector<P> G[MAXN];
double dis[MAXN];
bool vis[MAXN];
priority_queue<pair<double, int>> Q;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int a, b;
    double c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        G[a].emplace_back(make_pair(b, c));
    }
    dis[s] = 1;
    Q.push(P(dis[s], s));
    while (!Q.empty()) {
        nP u = Q.top();
        Q.pop();
        if (vis[u.second]) {
            continue;
        }
        if (u.first > dis[u.second]) {
            continue;
        }
        vis[u.second] = true;
        for (auto it : G[u.second]) {
            if (vis[it.first]) {
                continue;
            }
            if (dis[u.second] * it.second > dis[it.first]) {
                dis[it.first] = dis[u.second] * it.second;
                Q.push(nP(dis[it.first], it.first));
            }
        }
    }
    if (!vis[t]) {
        cout << "orz" << endl;
    } else {
        cout << fixed << setprecision(4) << dis[t] << endl;
    }
    return 0;
}