#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int k = int(sqrt(2 * (n + 1))) - 1;
    if (k % 2 == 0) {
        k -= 1;
    }
    if (n < 7) {
        cout << n << endl;
        exit(0);
    }
    for (int i = k; i >= 1; i -= 2) {
        for (int j = 1; j <= (k - i) / 2; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            cout << c;
        }
        cout << endl;
    }
    for (int i = 3; i <= k; i += 2) {
        for (int j = 1; j <= (k - i) / 2; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            cout << c;
        }
        cout << endl;
    }
    cout << n - ((k + 1) * (k + 1) / 2 - 1) << endl;
    return 0;
}