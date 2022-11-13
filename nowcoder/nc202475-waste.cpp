#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> T[100010];
ll val[100010];
bool vis[100010];
queue<pair<int, int>> Q;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    // Root:1
    int maxpos = 1;
    ll maxval = 0;
    vis[1] = true;
    Q.push(make_pair(1, val[1]));
    while (!Q.empty()) {
        pair<int, ll> cur = Q.front();
        Q.pop();
        if (cur.second >= maxval) {
            maxval = cur.second;
            maxpos = cur.first;
        }
        for (int i = 0; i < T[cur.first].size(); i++) {
            int u = T[cur.first][i];
            if (!vis[u]) {
                vis[u] = true;
                Q.push(make_pair(u, cur.second + val[u]));
            }
        }
    }
    // Root:maxpos
    Q.push(make_pair(maxpos, val[maxpos]));
    maxval = 0;
    memset(vis, 0, sizeof(vis));
    vis[maxpos] = true;
    while (!Q.empty()) {
        pair<int, ll> cur = Q.front();
        Q.pop();
        if (cur.second > maxval) {
            maxval = cur.second;
        }
        for (int i = 0; i < T[cur.first].size(); i++) {
            int u = T[cur.first][i];
            if (!vis[u]) {
                vis[u] = true;
                Q.push(make_pair(u, cur.second + val[u]));
            }
        }
    }
    cout << maxval << endl;
    return 0;
}