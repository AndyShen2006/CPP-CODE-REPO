#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long n, m, rn, rm;
        cin >> rn >> rm;
        if (rn % 2 == 0) {
            n = rn + 1;
        } else {
            n = rn;
        }
        if (rm % 2 == 0) {
            m = rm + 1;
        } else {
            m = rm;
        }
        long long ans = 2 * ((m / 2 - 1) * 3 + 2 * 2) + (n / 2) * (m / 2) * 4 + (n / 2 - 1) * ((m / 2 - 1) * 4 + 2 * 3);
        if (rn % 2 == 0) {
            ans -= ((m / 2 - 1) * 3 + 2 * 2) + (m / 2) * 1;
        }
        if (rm % 2 == 0) {
            ans -= (n / 2) * 1 + 2 * 2 + (n / 2 - 1) * 3;
        }
        if (rm % 2 == 0 && rn % 2 == 0) {
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}