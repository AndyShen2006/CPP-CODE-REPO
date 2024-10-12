#include <bits/stdc++.h>

using namespace std;

int a[10];
int f[10][10];
int dfs(int pos, bool limit, bool six, int cnt)
{
    if (!pos) { // 到达递归终点
        return 1;
    }
    if (!limit && !six && ~f[pos][cnt]) { // 没有特殊限制且已经搜过
        return f[pos][cnt];
    }
    int ub = limit ? a[pos] : 9; // 判断上界
    int ans = 0;
    for (int i = 0; i <= ub; i++) {
        if (six && i == 2) {
            continue; // 62，跳过
        }
        if (i == 4) {
            continue; // 4，跳过
        }
        int tmp = dfs(pos - 1, limit && i == ub, i == 6, cnt + 1);
        ans += tmp;
    }
    if (!limit && !six) {
        f[pos][cnt] = ans;
    }
    return ans;
}

int solve(int x)
{
    int len = 0;
    while (x > 0) {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, true, false, 0);
}

int main()
{
    memset(f, -1, sizeof(f));
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        // cerr << solve(m) << ' ' << solve(n - 1) << endl;
        cout << solve(m) - solve(n - 1) << endl;
    }
    return 0;
}