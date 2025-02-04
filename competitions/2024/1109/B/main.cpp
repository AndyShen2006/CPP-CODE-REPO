#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if ((n / i) % 2 == 1) {
                ans ^= i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}