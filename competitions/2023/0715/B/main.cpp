#include <bits/stdc++.h>

using namespace std;

int a[1000010];

int main()
{
    int n, k;
    cin >> n >> k;
    int x, m = 0, sm = 0, last = -114514;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x]++;
    }
    for (auto it : a) {
        if (it == 0) {
            continue;
        }
        if (last == -114514) {
            last = it;
        } else if (it != last) {
            last = -1;
        }
        if (it >= m) {
            sm = m;
            m = it;
        }
    }
    if (k >= m || (k >= m - k && k >= sm) || k + k >= n) {
        cout << "pigstd" << endl;
        exit(0);
    }
    int ans = 0;
    for (auto it : a) {
        if (it == 0) {
            continue;
        }
        if ((k + k >= m - it && (it + k >= sm) || it + k >= m || it + k + k >= n)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}