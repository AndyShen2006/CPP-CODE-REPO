#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a, ans = 1, m = 0;
    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            cin >> a;
            ans = ans * a % 998244353;
        }
        cout << ans << endl;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        m = max(m, a);
    }
    if (m == 0) {
        ans = 0;
    } else {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}