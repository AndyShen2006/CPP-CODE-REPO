// 打表出省一！
#include <bits/stdc++.h>

using namespace std;

map<int, string> ans = {
    { 0, "1-1" },
    { 1, "1" },
    { 2, "1+1" },
    { 3, "1+1-4+5" },
    { 4, "1-1+4" },
    { 6, "1+1+4" },
    { 8, "1-1+4+5-1" },
    { 9, "1-1+4+5" },
    { 10, "1+1+4+5-1" },
    { 11, "1+1+4+5" },
    { 12, "1+1+4+5+1" },
    { 14, "1+1+4+5-1+4" },
    { 16, "1+1+4+5+1+4" }
};

int main()
{
    freopen("coin.in", "r", stdin);
    freopen("coin.out", "w", stdout);
    int T;
    cin >> T;
    if (T == 1) {
        int n;
        cin >> n;
        if (ans.find(n) != ans.end()) {
            cout << ans[n] << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        for (int i = 1; i <= T; i++) {
            cout << -1 << endl;
        }
    }
    return 0;
}