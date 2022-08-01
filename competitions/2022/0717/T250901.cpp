#include <bits/stdc++.h>

using namespace std;

string str;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1 || n == m) {
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                cout << 'l';
            } else {
                cout << 'r';
            }
        }
    } else if (k >= 3) {
        // Generate m
        for (int i = 1; i <= m / 2; i++) {
            str.push_back('l');
            str.push_back('r');
        }
        for (int i = 1; i <= n - m; i++) {
            if (i % 4 == 0) {
                str.push_back('r');
            } else {
                str.push_back('l');
            }
        }
        cout << str << endl;
    } else {
        for (int i = 1; i <= (m - 4) / 2; i++) {
            str.push_back('l');
            str.push_back('r');
        }
        for (int i = 1; i <= n - m + 4; i++) {
            if (i % 3 == 1) {
                str.push_back('l');
            } else {
                str.push_back('r');
            }
        }
        cout << str << endl;
    }
    return 0;
}