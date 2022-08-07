#include <bits/stdc++.h>

using namespace std;

set<int> G[2022];
queue<int> Q;
bool inq[2022];
int dis_s[2022], dis_t[2022];

void spfa(int n)
{
    Q.push(n);
    inq[n] = true;
    memset(dis_s, 0x3f, sizeof(dis_s));
    dis_s[n] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (auto it : G[u]) {
            if (dis_s[u] + 1 < dis_s[it]) {
                dis_s[it] = dis_s[u] + 1;
                if (!inq[it]) {
                    inq[it] = true;
                    Q.emplace(it);
                }
            }
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    spfa(b);
    for (int i = 1; i <= n; i++) {
        dis_t[i] = dis_s[i];
    }
    spfa(a);
    int ans = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dis_s[i] + 1 + dis_t[j] < dis_s[b] || dis_s[j] + 1 + dis_t[i] < dis_s[b]) {
                // cout << i << ' ' << j << endl;
                ans--;
            }
        }
    }
    cout << ans - m << endl;
    return 0;
}