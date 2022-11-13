#include <bits/stdc++.h>
#define inf 1 << 26
using namespace std;
int n, m, w[18][18];
int f[1 << 18][18], ans = inf;
int x, y, z;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = inf;
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        w[x - 1][y - 1] = min(w[x - 1][y - 1], z);
    }
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i ^ 1 << j) >> k & 1) {
                        f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + w[k][j]);
                    }
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
        ans = min(ans, f[(1 << n) - 1][i]);
    if (ans == inf)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}
