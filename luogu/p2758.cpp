#include <bits/stdc++.h>

using namespace std;

int dp[2010][2010];

int main()
{
    // Input
    string src, a, b;
    cin >> src;
    int alen = src.size();
    a.push_back(' ');
    for (auto it : src) {
        a.push_back(it);
    }
    cin >> src;
    b.push_back(' ');
    for (auto it : src) {
        b.push_back(it);
    }
    int blen = src.size();
    // Initialization
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= blen; i++) {
        dp[0][i] = i;
    }
    for (int i = 0; i <= alen; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({ dp[i][j], dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
            }
        }
    }
    cout << dp[alen][blen] << endl;
    return 0;
}