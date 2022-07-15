#include <bits/stdc++.h>

using namespace std;

int a[51][51];
int b[51][51];

void show(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void copy(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = b[i][j];
        }
    }
}

int main()
{
    freopen("data/martix.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int q;
    cin >> q;
    int p;
    for (int i = 1; i <= q; i++) {
        cin >> p;
        if (p == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    b[n - j + 1][i] = a[i][j];
                }
            }
            copy(n);
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    b[j][n - i + 1] = a[i][j];
                }
            }
            copy(n);
        }
    }
    show(n);
    return 0;
}