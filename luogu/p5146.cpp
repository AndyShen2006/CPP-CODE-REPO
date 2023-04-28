#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[1000010];
ll sub[1000010];
ll dp[1000010];

inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        sub[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] + sub[i], sub[i]);
    }
    ll ans = LONG_LONG_MIN;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}