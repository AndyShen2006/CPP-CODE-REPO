#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("data/dist1.in", "r", stdin);
    int T, type;
    cin >> T >> type;
    while (T--) {
        string s;
        cin >> s;
        size_t mn = 0, mx = 0;
        if (s[s.size() - 1] == s[s.size() - 2]) {
            mn = 1;
        } else if (s[s.size() - 1] == s[s.size() - 3]) {
            mn = 2;
        } else {
            mn = 3;
        }
        size_t i;
        for (i = 1; i < s.size(); i++) {
            mx++;
            if (s[i] != s[i - 1]) {
                break;
            }
        }
        mx += int(s.size() - i) << 1;
        mx = max(mx, s[0] == s[s.size() - 1] ? s.size() - 1 : s.size() + 1);
        if (type == 0) {
            cout << mx << endl;
        } else if (type == 1) {
            cout << mn << endl;
        } else {
            cout << mx << ' ' << mn << endl;
        }
    }
    return 0;
}