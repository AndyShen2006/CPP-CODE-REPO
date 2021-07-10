#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
ll a[100001];

bool check(ll len)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] / len;
    }
    return cnt >= m;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    ll l = 1, r = 1 << 30, mid, ans;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        r = min(r, a[i]);
    }
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}
