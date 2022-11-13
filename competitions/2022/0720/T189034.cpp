#include <bits/stdc++.h>

using namespace std;

int b[50001];
int dp[50001][2];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(b[i] - 1));
        dp[i][1] = max(dp[i - 1][0] + abs(b[i] - 1), dp[i - 1][1] + abs(b[i] - b[i - 1]));
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}