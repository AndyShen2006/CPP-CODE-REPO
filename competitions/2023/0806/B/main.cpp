#include <bits/stdc++.h>

using namespace std;

long long a[100010];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] + a[i - 1] > x) {
            long long tmp = a[i] + a[i - 1] - x;
            a[i] = a[i] - tmp;
            ans += tmp;
        }
    }
    cout << ans << endl;
    return 0;
}