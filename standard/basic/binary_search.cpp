#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[100];
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (x <= a[mid])
            r = mid;
        else
            l = mid + 1;
        cout << l << ' ' << r << endl;
    }
    cout << lower_bound(a + 1, a + n + 2, x) - a << endl;
    cout << l << endl;
    return 0;
}