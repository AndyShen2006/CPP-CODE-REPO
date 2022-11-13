#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, x;
ll a[100001];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &x);
        ll l = lower_bound(a + 1, a + n + 1, x, [](int a, int b) -> bool { return a >= b; }) - a - 1;
        ll h = upper_bound(a + 1, a + n + 1, x, [](int a, int b) -> bool { return a >= b; }) - a;
        if (a[l] != x) {
            printf("-1\n");
        } else {
            printf("%lld\n", (l + h) / 2);
        }
        //printf("l:%lld,r:%lld\n", l, h);
    }
    return 0;
}
