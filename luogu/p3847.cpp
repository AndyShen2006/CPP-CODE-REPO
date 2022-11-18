#include <bits/stdc++.h>

using namespace std;

int a[3010];
int dp[3010][3010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            if (a[i] == a[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min({ dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] }) + 1;
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}