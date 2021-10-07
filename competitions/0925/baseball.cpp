#include <bits/stdc++.h>

using namespace std;

long long a[1010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int x = 1; x <= n - 2; x++) {
        for (int y = x + 1; y <= n - 1; y++) {
            for (int z = y + 1; z <= n; z++) {
                if (a[y] - a[x] <= a[z] - a[y] && a[z] - a[y] <= 2 * (a[y] - a[x])) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}