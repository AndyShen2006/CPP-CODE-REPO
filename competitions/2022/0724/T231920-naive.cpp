#include <bits/stdc++.h>

using namespace std;

int a[4000001];

inline int value(int l, int r)
{
    int maxv = 0, minv = INT_MAX;
    for (int i = l; i <= r; i++) {
        maxv = max(maxv, a[i]);
        minv = min(minv, a[i]);
    }
    // cout << maxv << ' ' << minv << endl;
    return maxv - minv - r + l - 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // cout << value(1, 3) << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = max(ans, value(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}