#include <bits/stdc++.h>

using namespace std;

int a[101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m = 0;
    for (int i = 1; i <= n; i++) {
        m = max(m, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == m) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}