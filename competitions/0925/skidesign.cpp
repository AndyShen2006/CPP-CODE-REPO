#include <bits/stdc++.h>

using namespace std;
int a[1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n / 2; i++) {
        int tmp = 0;
        do {
            sort(a + 1, a + n + 1);
            int sub = a[n - i] - a[i + 1] - 17;
            int mid = sub / 2;
            a[n] -= mid, a[1] += sub - mid;
            tmp += mid * mid + (sub - mid) * (sub - mid);
        } while (a[n - i] - a[i + 1] > 17);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
/*
5
20
4
1
24
21
*/