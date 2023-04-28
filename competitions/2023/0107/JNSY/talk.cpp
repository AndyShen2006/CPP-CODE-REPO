#include <bits/stdc++.h>

using namespace std;

int dp[5000][5000];

int main()
{
    string poem1, poem2;
    getline(cin, poem1);
    getline(cin, poem2);
    int ans = 0;
    for (int i = 0; i < poem1.size(); i++) {
        for (int j = 0; j < poem2.size(); j++) {
            if (poem1[i] == poem2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
            ans = max(ans, dp[i + 1][j + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}