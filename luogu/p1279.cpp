#include <bits/stdc++.h>

using namespace std;

int dp[2010][2010];

int main()
{
    // Input
    string src, a, b;
    int alen, blen;
    int k;
    cin >> src;
    alen = static_cast<int>(src.size());
    a.push_back(' ');
    for (auto it : src) {
        a.push_back(it);
    }
    cin >> src;
    blen = static_cast<int>(src.size());
    b.push_back(' ');
    for (auto it : src) {
        b.push_back(it);
    }
    cin >> k;
    // Initialization
    for (int i = 1; i <= alen; i++) {
        dp[i][0] = dp[i - 1][0] + k;
    }
    for (int i = 1; i <= blen; i++) {
        dp[0][i] = dp[0][i - 1] + k;
    }
    // Main
    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            dp[i][j] = min({ dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + abs((int)a[i] - (int)b[j]) });
        }
    }
    cout << dp[alen][blen] << endl;
    return 0;
}