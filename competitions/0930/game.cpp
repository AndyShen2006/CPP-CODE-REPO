#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main()
{
    int n;
    int ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i - 1) {
            ans = i;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}