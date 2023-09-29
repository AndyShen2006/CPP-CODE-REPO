#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll xs[100010], ys[100010], preX[100010], preY[100010];

int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs + 1, xs + n + 1);
    sort(ys + 1, ys + n + 1);
    for (int i = 1; i <= n; i++) {
        preX[i] = preX[i - 1] + xs[i];
        preY[i] = preY[i - 1] + ys[i];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << preX[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << preY[i] << ' ';
    // }
    // cout << endl;
    int tx, ty;
    for (int i = 1; i <= m; i++) {
        cin >> tx >> ty;
        auto xit = lower_bound(xs + 1, xs + n + 1, tx);
        auto yit = lower_bound(ys + 1, ys + n + 1, ty);
        // cout << xit - xs - 1 << ' ' << n - (xit - xs - 1) << endl;
        // cout << yit - ys - 1 << ' ' << n - (yit - ys - 1) << endl;
        cout << (tx * (xit - xs - 1) - preX[xit - xs - 1]) + (preX[n] - preX[xit - xs - 1] - tx * (n - (xit - xs - 1))) + (ty * (yit - ys - 1) - preY[yit - ys - 1]) + (preY[n] - preY[yit - ys - 1] - ty * (n - (yit - ys - 1))) << endl;
    }

    return 0;
}