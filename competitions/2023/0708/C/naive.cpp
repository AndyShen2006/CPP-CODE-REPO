#include <bits/stdc++.h>

using namespace std;

int a[5000010], b[5000010], sa, sb;

int main()
{
    int n, m;
    int flag = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (b[i] != b[i - 1]) {
            flag++;
            sa = b[i];
            sb = b[i - 1];
        }
    }
    if (flag == 1) {
        int ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            // cout << cnt << ' ';
            if (a[i] != a[i - 1]) {
                ans += (1 << cnt) - 1;
                cnt = 0;
            }
            if (a[i] == sa) {
                cnt++;
            }
        }
        // cout << endl;
        cout << ans << endl;
    } else if (flag == 2) {

    } else {
        exit(0);
    }
    return 0;
}