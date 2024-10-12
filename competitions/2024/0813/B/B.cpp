#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
int a[MAX_N];

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int n;
    cin >> n;
    int firstOne = 0, lastOne = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            if (!firstOne) {
                firstOne = i;
            }
            lastOne = i;
            ans++;
        }
    }
    // cout << firstOne << ' ' << lastOne << endl;
    for (int i = 1; i < firstOne; i++) {
        if (a[i] == 2) {
            ans++;
            break;
        }
    }
    for (int i = lastOne + 1; i <= n; i++) {
        if (a[i] == 3) {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}