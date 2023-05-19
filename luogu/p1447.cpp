#include <bits/stdc++.h>

using namespace std;

long long f[100010], ans;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = min(m, n); i >= 1; i--) {
        f[i] = 1LL * (n / i) * (m / i);
        for (int j = i + i; j <= min(m, n); j += i) {
            f[i] -= f[j];
        }
        ans += (i + i - 1) * f[i];
    }
    cout << ans << endl;
    return 0;
}