#include <bits/stdc++.h>

using namespace std;

int dp[1005];
const int m[6] = { 1, 2, 3, 5, 10, 20 };

int main()
{
    int a[6], cnt = 0;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        if (dp[i] >= 0)
            cnt++;
    }
    printf("Total=%d\n", cnt);
    return 0;
}
