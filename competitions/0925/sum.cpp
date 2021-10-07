#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
void dfs(int now, int nxt)
{
    if (nxt == n) {
        if (now == n) {
            ans++;
        }
        return;
    }
    dfs(now + nxt, nxt + 1);
    dfs(now - nxt, nxt + 1);
}

int main()
{
    cin >> n;
    dfs(-1, 2);
    cout << ans << endl;
    return 0;
}