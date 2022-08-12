#include <bits/stdc++.h>

using namespace std;

bool notput[20][20];
int f[20][1 << 20];

int main()
{
    int n, m; // n->棋盘大小，m->不可以放置的格子个数
    cin >> n >> m;
    int r, c;
    for (int i = 1; i <= m; i++) {
        cin >> r >> c;
        notput[r - 1][c - 1] = true; //从0，0开始
    }
    //预处理
    for (int i = 0; i < n; i++) {
        f[0][1 << i] = 1;
    }
    //主循环
    for (int i = 1; i < n; i++) { //第i行
        for (int j = 1; j < n; j++) { //放在第j列
            for (int k = 0; k < 1 << n; k++) { //枚举第i-1层情况
                if ((k & (1 << (j - 1))) == 0 && !notput[i][j]) { //不与前面状态冲突且这个格子能放
                    f[i][k + (1 << (j - 1))] += f[i - 1][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        ans = max(ans, f[n - 1][i]);
    }
}