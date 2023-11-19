#include <bits/stdc++.h>

using namespace std;

constexpr int R = 3000020;
vector<int> is[R];
int dp[R];

int main()
{
    int n, maxr = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        is[y].push_back(x);
        maxr = max(maxr, y);
    }
    for (int i = 1; i <= maxr; i++) {
        dp[i] = dp[i - 1];
        for (auto it : is[i]) {
            dp[i] = max(dp[i], dp[it - 1] + (i - it + 1));
        }
    }
    int ans = 0;
    for (int i = 1; i <= maxr; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}