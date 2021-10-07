#include <bits/stdc++.h>

using namespace std;

vector<int> T[200001];
int val[200001], size[200001];
int S = 0;
//Calculate par and size
void dfs1(int u, int p, int dep)
{
    int v;
    S += u * dep;
    size[u] = val[u];
    if (T[u].size() == 1 && u != p) {
        return;
    }
    for (int i = 0; i < T[u].size(); i++) {
        v = T[u][i];
        if (v == p) {
            continue;
        }
        dfs1(v, u, dep + 1);
        size[u] += size[v];
    }
}

int dp[200001];
void dfs2(int u, int p)
{
    int v;
    if (T[u].size() == 1 && u != p) {
        return;
    }
    for (int i = 0; i < T[u].size(); i++) {
        v = T[u][i];
        if (v == p) {
            continue;
        }
        dp[v] = dp[u] + 2 * size[v] - size[1];
        dfs2(v, u);
    }
}

int main()
{
    //freopen("data/D1.in", "r", stdin);
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs1(1, 1, 0);
    dfs2(1, 1);
    //cout << S << endl;
    int ans = S;
    for (int i = 2; i <= n; i++) {
        //cout << dp[i] << endl;
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}