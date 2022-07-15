#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans;
int main()
{
    // freopen("data/count10.in", "r", stdin);
    // freopen("data/count10.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                ans++;
            else
                ans += 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}