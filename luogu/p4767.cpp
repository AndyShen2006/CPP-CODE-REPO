#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_V = 3010, MAX_P = 310;
int vs[MAX_V], dp[MAX_V][MAX_P];
int wds[MAX_V][MAX_V];

int main()
{
    int V, P;
    cin >> V >> P;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= V; i++) {
        cin >> vs[i];
    }
    for (int l = 1; l <= V; l++) {
        wds[l][l] = 0;
        for (int r = l + 1; r <= V; r++) {
            wds[l][r] = wds[l][r - 1] + vs[r] - vs[(l + r) >> 1];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= P; j++) {
            for (int k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + wds[k + 1][i]);
            }
        }
    }
    cout << dp[V][P] << endl;
    return 0;
}