#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        int ans = 2;
        if ((n & m) == n) {
            ans--;
        }
        if ((n | m) == n) {
            ans--;
        }
        cout << ans << endl;
    }
}