// #include <bits/stdc++.h>
// using namespace std;

// struct node {
//     int child[10001], u, v, num;
// } a[10000];

// int n, m;

// int oiqidong(int x, int nowu, int nowv)
// {
//     int tmax = nowv;
//     for (int i = 1; i <= a[x].num; i++) {
//         int nex = a[x].child[i];
//         if (nowu + a[nex].u <= m)
//             tmax = max(tmax, oiqidong(nex, nowu + a[nex].u, nowv + a[nex].v));
//     }
//     return tmax;
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i].u >> a[i].v >> a[i].num;
//         for (int j = 1; j <= a[i].num; j++)
//             cin >> a[i].child[j];
//     }

//     cout << oiqidong(1, a[1].u, a[1].v) << endl;
//     return 0;
// }

// /* 6 10 1 1 2 2 3 2 3 2 4 5 3 4 2 5 6 4 6 0 6 6 0 7 10 0 */
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