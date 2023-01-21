#include <bits/stdc++.h>

using namespace std;

signed main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    string s;
    cin >> s;
    int ans = 1;
    bool flag = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            ans++;
        }
    }
    cout << (ans + 1) / 2 << endl;
    int p;
    char c;
    for (int i = 1; i <= q; i++) {
        cin >> p >> c;
        if (s[p - 1] == c) {
            cout << (ans + 1) / 2 << endl;
            continue;
        }
        ans = ans - ((s[p - 2] == c) + (s[p] == c)) + ((s[p - 2] == s[p - 1]) + (s[p] == s[p - 1]));
        s[p - 1] = c;
        cout << (ans + 1) / 2 << endl;
    }
    return 0;
}