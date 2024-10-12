#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[20];
ll f[20][20][2];

ll dfs(int digit, int pos, bool limit, bool lead, int cnt)
{
    if (!pos) {
        return cnt;
    }
    ll& cur = f[pos][cnt][digit != 0];
    if (!limit && !lead && ~cur) {
        return cur;
    }
    int ub = limit ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= ub; i++) {
        if (lead && digit == 0 && i == 0) {
            ans += dfs(digit, pos - 1, limit && (i == ub), lead && (i == 0), 0);
        } else {
            ans += dfs(digit, pos - 1, limit && (i == ub), lead && (i == 0), cnt + (i == digit));
        }
    }
    if (!limit && !lead) {
        cur = ans;
    }
    return ans;
}

void solve(ll l, ll r)
{
    ll lAns[10], rAns[10];
    int len = 0;
    l--;
    while (l > 0) {
        a[++len] = int(l % 10);
        l /= 10;
    }
    for (int i = 0; i <= 9; i++) {
        lAns[i] = dfs(i, len, true, true, 0);
    }
    len = 0;
    while (r > 0) {
        a[++len] = int(r % 10);
        r /= 10;
    }
    for (int i = 0; i <= 9; i++) {
        rAns[i] = dfs(i, len, true, true, 0);
    }
    // for (int i = 0; i <= 9; i++) {
    //     cerr << lAns[i] << ' ' << rAns[i] << endl;
    // }
    for (int i = 0; i <= 9; i++) {
        cout << rAns[i] - lAns[i] << ' ';
    }
    cout << endl;
}

int main()
{
    memset(f, -1, sizeof(f));
    ll l, r;
    cin >> l >> r;
    solve(l, r);
    return 0;
}