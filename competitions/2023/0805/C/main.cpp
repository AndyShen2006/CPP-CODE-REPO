#include <bits/stdc++.h>

using namespace std;

vector<int> T[1000010];
pair<int, pair<int, bool>> dep[1000010];
int pre[1000010], sum;

void dfs(int x, int par, int depth)
{
    dep[x].first = depth;
    dep[x].second.first = x;
    for (auto it : T[x]) {
        if (it == par) {
            continue;
        }
        dfs(it, x, depth + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1, 1);
    // for (int i = 1; i <= n; i++) {
    //     cout << dep[i] << ' ';
    // }
    // cout << endl;
    sort(dep + 1, dep + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + dep[i].first;
        sum += dep[i].first;
    }
    if (sum & 1) {
        cout << -1 << endl;
        return 0;
    }
    sum /= 2;
    int end, start = -1;
    for (end = 1; end <= n; end++) {
        auto it = lower_bound(pre + 1, pre + end + 1, pre[end] - sum);
        if (pre[end] - *it == sum) {
            start = it - pre;
            break;
        }
    }
    if (start == -1) {
        cout << -1 << endl;
        return 0;
    }
    // cout << start << endl;
    for (int i = 1; i <= start; i++) {
        dep[i].second.second = false;
    }
    for (int i = start + 1; i <= end; i++) {
        dep[i].second.second = true;
    }
    for (int i = end + 1; i <= n; i++) {
        dep[i].second.second = false;
    }
    sort(dep + 1, dep + n + 1, [](auto l, auto r) -> bool { return l.second.first < r.second.first; });
    for (int i = 1; i <= n; i++) {
        cout << dep[i].second.second << ' ';
    }
    cout << endl;
    return 0;
}