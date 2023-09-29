// 暴力出奇迹！
#include <bits/stdc++.h>

using namespace std;

int a[1010];
long long dp[1010][1010]; // 跳到i位置，已经跳了j步时的最大得分

int main()
{
    freopen("jlb.in", "r", stdin);
    freopen("jlb.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + abs(a[i] - a[k]));
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][m]);
    }
    cout << ans << endl;
    return 0;
}