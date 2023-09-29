#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 998244353;
typedef long long ll;
ll sum;

int main()
{
    freopen("reset.in", "r", stdin);
    freopen("reset.out", "w", stdout);
    int n;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    sum <<= 1;
    int pow = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + pow * sum) % MOD;
        pow *= 10;
    }
    cout << ans << endl;
    return 0;
}