#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 40;

pair<int, int> G[MAX_N];
ll score[MAX_N], pre[MAX_N];

int build(int l, int r)
{
    if (l > r) {
        return 0;
    }
    int rt = l;
    ll m = pre[r] - pre[l - 1];
    ll sum = 0;
    for (int i = l; i <= r; i++) {
        sum += score[i];
        rt = i;
        if (sum >= m / 2) {
            break;
        }
    }
    G[rt].first = build(l, rt - 1);
    G[rt].second = build(rt + 1, r);
    return rt;
}

ll calc(int x)
{
    if (x == 0) {
        return 1;
    }
    if (!G[x].first && !G[x].second) {
        return score[x];
    }
    ll lAns = calc(G[x].first);
    ll rAns = calc(G[x].second);
    // cout << x << ' ' << lAns << ' ' << rAns << endl;
    return lAns * rAns + score[x];
}

void pre_order(int x)
{
    cout << x << ' ';
    if (G[x].first) {
        pre_order(G[x].first);
    }
    if (G[x].second) {
        pre_order(G[x].second);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
        pre[i] = pre[i - 1] + score[i];
    }
    int rt = build(1, n);
    cout << calc(rt) << endl;
    pre_order(rt);
    cout << endl;
    return 0;
}