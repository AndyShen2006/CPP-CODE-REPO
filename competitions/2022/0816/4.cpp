#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    string a, b;
    a.reserve(100000);
    b.reserve(100000);
    for (int i = 1; i <= T; i++) {
        cin >> a >> b;
        if ((*(a.end() - 1) - '0') % 2 == 1 && (*(b.end() - 1) - '0') % 2 == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}