#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sid;
    cin >> sid;
    if (sid == 1) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            long long ans, v[200010], c, tmp;
            for (int i = 1; i <= n; i++) {
                cin >> v[i];
            }
            for (int i = 1; i <= n; i++) {
                cin >> c;
                ans = (ans + v[i] * c) % 998244353;
            }
            for (int i = 1; i <= n - 1; i++) {
                cin >> tmp;
            }
            cout << ans << endl;
        }
    }
    return 0;
}