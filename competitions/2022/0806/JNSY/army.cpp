#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n - 1; i++) {
        if (a[i + 1] - a[i - 1] < d) {
            a[i] = a[i - 1];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}