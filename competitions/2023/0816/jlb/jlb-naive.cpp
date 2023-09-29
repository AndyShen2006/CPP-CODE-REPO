// 暴力出奇迹！
#include <bits/stdc++.h>

using namespace std;

int a[1010];
long long dp[1010][1010]; // 已经跳了i步跳到j位置时的最大得分

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("jlb.in", "r", stdin);
    freopen("jlb.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(a[j] - a[k]));
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[m][i]);
    }
    cout << ans << endl;
    return 0;
}