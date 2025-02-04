#include <bits/stdc++.h>

using namespace std;

set<string> dicts;

inline bool check(const string& a, const string& b)
{
    if (a.size() != b.size()) {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            cnt++;
        }
    }
    if (cnt + cnt >= a.size()) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    // freopen("data/A1.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        dicts.insert(tmp);
    }
    for (int i = 1; i <= m; i++) {
        string tmp;
        cin >> tmp;
        if (dicts.find(tmp) != dicts.end()) {
            cout << "correct" << endl;
        } else {
            bool flag = false;
            string ans;
            for (const auto& it : dicts) {
                if (check(it, tmp)) {
                    flag = true;
                    ans = it;
                    break;
                }
            }
            if (flag) {
                cout << ans << endl;
            } else {
                cout << "error" << endl;
            }
        }
    }
    return 0;
}