#include <bits/stdc++.h>

using namespace std;

set<int> G[2010];
queue<int> Q;
bool inq[2010];
int dis_s[2010];

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

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((G[i].find(j) == G[i].end()) && abs(dis_s[i] - dis_s[j]) <= 1) {
                cout << i << ' ' << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}