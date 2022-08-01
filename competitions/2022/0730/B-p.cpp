#include <bits/stdc++.h>

using namespace std;

bool bi[65537];

int main()
{
    // freopen("data/B1.in", "r", stdin);
    int s, t;
    cin >> s >> t;
    int n, x, y, b, maxb;
    for (int i = 1; i <= t; i++) {
        cin >> n >> x >> y;
        if (s == 1) {
            memset(bi, 0, sizeof(bi));
            maxb = 0;
            for (int j = 1; j <= n; j++) {
                cin >> b;
                maxb = max(maxb, b);
                bi[b] = true;
            }
            for (int j = maxb; j >= 0; j--) {
                cout << bi[j];
            }
            cout << endl;
            for (int j = 1; j <= y; j++) {
                cout << '|';
            }
            for (int j = 1; j <= x; j++) {
                cout << '^';
            }
            cout << endl;
        } else if (s == 2) {
            memset(bi, 0, sizeof(bi));
            maxb = 0;
            for (int j = 1; j <= n; j++) {
                cin >> b;
                maxb = max(maxb, b);
                bi[b] = true;
            }
            if (y == 0 && x % 2 == 0) {
                cout << 0 << endl;
                for (int j = 1; j <= x; j++) {
                    cout << '^';
                }
                for (int j = 1; j <= y; j++) {
                    cout << '|';
                }
                cout << endl;
            } else {
                for (int j = maxb; j >= 0; j--) {
                    cout << bi[j];
                }
                cout << endl;
                for (int j = 1; j <= x; j++) {
                    cout << '^';
                }
                for (int j = 1; j <= y; j++) {
                    cout << '|';
                }
                cout << endl;
            }
        }
    }
    return 0;
}