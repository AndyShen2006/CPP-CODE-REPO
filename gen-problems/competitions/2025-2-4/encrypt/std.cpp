#include <bits/stdc++.h>

using namespace std;

vector<pair<string, char>> strs;

int main()
{
    string s;
    cin >> s;
    for (int i = s.size(); i >= 0; i--) {
        if (i == 0) {
            strs.emplace_back(s.substr(i, s.size()), '$');
        } else {
            strs.emplace_back(s.substr(i, s.size()), s[i - 1]);
        }
    }
    // for (const auto& it : strs) {
    //     cerr << it.first << ' ' << it.second << endl;
    // }
    sort(strs.begin(), strs.end());
    // for (const auto& it : strs) {
    //     cerr << it.first << ' ' << it.second << endl;
    // }
    for (const auto& it : strs) {
        cout << it.second;
    }
    cout << endl;
    return 0;
}