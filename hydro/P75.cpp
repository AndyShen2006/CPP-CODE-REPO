#include <bits/stdc++.h>

using namespace std;

int f[40][40];
int a[32];

int dfs(int pos, bool limit, int cnt, int mx)
{
    if (!pos) {
        return 1;
    }
    if (!limit && ~f[pos][cnt]) {
    }
}

int solve(int x, int b, int k)
{
    int len = 0;
    while (x > 0) {
        a[++len] = x % b;
        x /= b;
    }
    return dfs(len, true, 0, k);
}

int main()
{
    memset(f, -1, sizeof(f));
    int x, y, k, b;
    cin >> x >> y >> k >> b;
    cerr << solve(x - 1, b, k) << ' ' << solve(y, b, k);
    // cout << solve(y, b, k) - solve(x - 1, b, k) << endl;
    return 0;
}