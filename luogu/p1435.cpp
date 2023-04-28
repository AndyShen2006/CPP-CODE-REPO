#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int main()
{
    string src, str, rst;
    cin >> src;
    str.push_back(' ');
    rst.push_back(' ');
    for (auto it : src) {
        str.push_back(it);
        rst.push_back(it);
    }
    reverse(rst.begin() + 1, rst.end());
    int len = static_cast<int>(src.size());
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (str[i] == rst[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 1; i <= len; i++) {
    //     for (int j = 1; j <= len; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << str << endl
    //      << rst << endl;
    cout << len - dp[len][len] << endl;
    return 0;
}