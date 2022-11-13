#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, ans = 0;
ll a[100001];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans += a + n + 1 - upper_bound(a + 1, a + n + 1, i + j);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
