#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e6 + 1;
int a[MAX_N];

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // freopen("data/exchange01.in", "r", stdin);
    int n, w, crt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> w;
    sort(a + 1, a + n + 1);
    crt = *upper_bound(a + 1, a + n + 1, w);
    if (!crt) {
        crt = a[n];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (crt >= a[i]) {
            cnt++;
            crt -= a[i];
        } else {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}