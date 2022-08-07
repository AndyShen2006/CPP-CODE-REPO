#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    long long ans = 0;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans += __gcd(j, k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}