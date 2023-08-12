#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> G[10010];
int us[10010], vs[10010], m;
int in[10010];

int dfs(int cur, int curU, int curV)
{
    int ans = curV;
    for (auto it : G[cur]) {
        if (curU + us[it] <= m) {
            ans = max(ans, dfs(it, curU + us[it], curV + vs[it]));
        }
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int to, tn;
        cin >> us[i] >> vs[i] >> tn;
        for (int j = 1; j <= tn; j++) {
            cin >> to;
            G[i].push_back(to);
            in[to]++;
        }
    }
    int ans;
    for (int i = 1; i <= n; i++) {
        ans = 0;
        if (in[i] == 0) {
            ans = max(ans, dfs(i, us[i], max(vs[i], 0ll)));
        }
    }
    cout << ans << endl;
    return 0;
}