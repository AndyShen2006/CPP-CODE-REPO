#include <bits/stdc++.h>

using namespace std;

double a[100010];

int main()
{
    freopen("data/p1471c.in", "r", stdin);
    freopen("data/p1471c.chk", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int op;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            double k;
            cin >> x >> y >> k;
            for (int i = x; i <= y; i++) {
                a[i] += k;
            }
        } else if (op == 2) {
            cin >> x >> y;
            double sum = 0;
            for (int i = x; i <= y; i++) {
                sum += a[i];
            }
            cout << fixed << setprecision(4) << sum / (y - x + 1) << endl;
        } else {
            cin >> x >> y;
            double arr = 0;
            for (int i = x; i <= y; i++) {
                arr += a[i];
            }
            arr /= (y - x + 1);
            double sum = 0;
            for (int i = x; i <= y; i++) {
                sum += (a[i] - arr) * (a[i] - arr);
            }
            cout << fixed << setprecision(4) << sum / (y - x + 1) << endl;
        }
        cout << op << ' ' << x << ' ' << y << endl;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}