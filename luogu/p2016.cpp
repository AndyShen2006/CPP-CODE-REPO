#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1510;
vector<int> T[MAX_N];
int dp[MAX_N][2]; // Vertex u, isSelected?--->The minimum answer.

void dfs(int x, int par)
{
    dp[x][0] = 0;
    dp[x][1] = 1;
    for (auto it : T[x]) {
        if (it == par) {
            continue;
        }
        dfs(it, x);
        dp[x][0] += dp[it][1];
        dp[x][1] += min(dp[it][0], dp[it][1]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 1; j <= k; j++) {
            int v;
            cin >> v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
    }
    dfs(0, -1);
    cout << min(dp[0][0], dp[0][1]) << endl;
    return 0;
}