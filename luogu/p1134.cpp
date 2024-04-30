#include <bits/stdc++.h>

using namespace std;

int qpow(int a, int x)
{
    int ans = 1;
    while (x) {
        if (x & 1) {
            ans = (ans * a) % 10;
        }
        a = (a * a) % 10;
        x >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int ans = 1, cnt2 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur % 2 == 0) {
            cnt2++;
            cur /= 2;
        }
        while (cur % 5 == 0) {
            cnt5++;
            cur /= 5;
        }
        ans *= cur;
        ans %= 10;
    }
    // cout << ans << ' ' << cnt2 - cnt5 << ' ' << qpow(2, cnt2 - cnt5) << endl;
    cout << ((ans * qpow(2, cnt2 - cnt5)) % 10) << endl;
    return 0;
}