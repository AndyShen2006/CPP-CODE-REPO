#include <bits/stdc++.h>

using namespace std;

int r[7000];
vector<int> G[7000];
int dp[7000][2];
bool notRoot[7000];

constexpr int ncome = 0;
constexpr int come = 1;

void dfs(int n)
{
    dp[n][ncome] = 0;
    dp[n][come] = r[n];
    for (auto it : G[n]) {
        dfs(it);
        dp[n][ncome] += max(dp[it][come], dp[it][ncome]);
        dp[n][come] += dp[it][ncome];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    int p, s;
    for (int i = 1; i <= n - 1; i++) {
        cin >> s >> p;
        G[p].push_back(s);
        notRoot[s] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!notRoot[i]) {
            dfs(i);
            cout << max(dp[i][come], dp[i][ncome]) << endl;
            exit(0);
        }
    }
    return 0;
}