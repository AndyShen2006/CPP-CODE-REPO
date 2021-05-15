#include <algorithm>
#include <iostream>

using namespace std;

const int maxN = 250;
int hd[maxN], tl[maxN], dp[maxN][maxN] = { { 0 } };
int n, j, ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> hd[i];
        hd[i + n] = hd[i]; //Role to List
    }
    for (int i = 1; i < n * 2; i++) {
        tl[i] = hd[i + 1];
        dp[i][i] = 0;
    }
    tl[n * 2] = hd[1];
    for (int t = 1; t <= n - 1; t++) {
        for (int i = 1; i <= 2 * n - t; i++) {
            j = i + t;
            for (int k = i; k < j; k++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + hd[i] * tl[k] * tl[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n - 1]);
    cout << ans << endl;
    return 0;
}
