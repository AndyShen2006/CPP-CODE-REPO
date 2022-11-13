#include <bits/stdc++.h>

using namespace std;

int f[9][9][1 << 9];
int num[1 << 9];

int main()
{
    int n, m;
    cin >> n >> m;
    //预处理
    for (int i = 0; i < 1 << 9; i++) {
        num[i] = __builtin_popcount(i);
    }
    for (int j = 0; j <= (1 << (n - 1)); j++) {
        if (j & (j << 1)) { //有两个连续的1
            continue;
        }
        f[0][num[j]][j]++;
    }

    for (int i = 1; i < n; i++) { //第i行
        for (int j = 0; j <= m; j++) { //已经放了j个国王
            for (int k = 0; k < 1 << n; k++) { //第i层的状态为k
                for (int p = 0; p < 1 << n; p++) { //第i-1层的状态为p
                    if ((k & p) == 0 && (k & (p << 1)) == 0 && (k & (p >> 1)) == 0) {
                        f[i][j][k] += f[i - 1][j - num[k]][p];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        if (num[i] == m) {
            ans = max(ans, f[n - 1][m][i]);
        }
    }
    cout << ans << endl;
    return 0;
}