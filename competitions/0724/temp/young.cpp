#include <bits/stdc++.h>

using namespace std;

int preHash[50];

int main()
{
    freopen("young.in", "r", stdin);
    freopen("young.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, pos;
    cin >> preHash[0] >> n;
    for (int i = 1;; i++) {
        preHash[i] = preHash[i - 1] * 2 - 150;
        if (preHash[i] < 0) {
            pos = i;
            break;
        }
    }
    int th, *hpos;
    for (int i = 1; i <= n; i++) {
        cin >> th;
        hpos = lower_bound(preHash, preHash + pos - 1, th);
        if (*hpos == th) {
            cout << hpos - preHash << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}