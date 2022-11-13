#include <bits/stdc++.h>

using namespace std;
constexpr int NUM = 1510;
typedef pair<int, int> P;
int dis[NUM];
bool inq[NUM];
bool vis[NUM];
vector<P> G[NUM];
queue<int> Q;

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    Q.push(1);
    inq[1] = true;
    while (!Q.empty()) {
        int u = Q.front();
        vis[u] = true;
        Q.pop();
        inq[u] = false;
        for (auto it : G[u]) {
            if (dis[u] + it.second > dis[it.first]) {
                dis[it.first] = dis[u] + it.second;
                if (!inq[it.first]) {
                    inq[it.first] = true;
                    Q.push(it.first);
                }
            }
        }
    }
    if (!vis[n]) {
        cout << -1 << endl;
    } else {
        cout << dis[n] << endl;
    }
    return 0;
}