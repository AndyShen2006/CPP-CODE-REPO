#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, ll> ivs[100010];
int n, m;

bool check(ll dis)
{
    int cnt = 0, tmp = 0;
    ll last = LONG_LONG_MIN;
    for (int i = 1; i <= m; i++) {
        ll l = ivs[i].first, r = ivs[i].second;
        l = max(l, last + dis);
        if (r - l >= 0) {
            tmp = int((r - l) / dis) + 1;
            // printf("%lld %lld %d\n", l, r, tmp);
            cnt += tmp;
            last = l + (tmp - 1) * dis;
        }
    }
    // cout << dis << ' ' << cnt << endl;
    return cnt >= n;
}

int main()
{
    freopen("distancing.in", "r", stdin);
    freopen("distancing.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ivs[i].first >> ivs[i].second;
    }
    sort(ivs + 1, ivs + m + 1);
    // ll l = 1, r = 1e18 + 10;
    ll l = 1, r = 10, mid = 0;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}