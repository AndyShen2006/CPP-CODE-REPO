#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans = 1;
    int bi = 1;
    for (int i = 1; i <= n; i++) {
        bi = (bi << 1) % MOD;
        ans = ans * (bi - 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}