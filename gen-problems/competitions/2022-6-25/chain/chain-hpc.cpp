#include <bits/stdc++.h>
using namespace std;
vector<int> p[400010], G[400010];
queue<int> q;
int m, n, a, b, indeg[400010], dp[400010];
int k, g[400010], r, ans;
void topu()
{
    for (int i = 1; i <= m; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            dp[i] = 1, g[++r] = i;
        }
    }
    while (!q.empty()) {
        k = q.front();
        q.pop();
        g[++r] = k;
        for (int j = 0; j < G[k].size(); j++) {
            indeg[G[k][j]]--;
            if (indeg[G[k][j]] == 0)
                q.push(G[k][j]);
        }
    }
}
int main()
{
    freopen("data/chain1.in", "r", stdin);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        p[b].push_back(a);
        G[a].push_back(b);
        indeg[b]++;
    }
    topu();
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < p[g[i]].size(); j++) {
            dp[g[i]] += dp[p[g[i]][j]];
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d-%d\n", i, dp[i]);
    }
    for (int i = 1; i <= m; i++) {
        if (G[i].size() == 0)
            ans += dp[i];
    }
    printf("%d\n", ans);
    return 0;
}