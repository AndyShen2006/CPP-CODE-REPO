#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a[0] == 'y' && b[0] == 'y' && c == "ding" && d == "zhen") {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}