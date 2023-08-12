#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;

int p[MAX_N], sm[MAX_N], em[MAX_N]; // sm[x]:start x,max str;em[x]:end x, max str
int mr, mid, ans;

int main()
{
    string iStr, str;
    cin >> iStr;
    str.push_back('~');
    str.push_back('~');
    str.push_back('#');
    for (auto it : iStr) {
        str.push_back(it);
        str.push_back('#');
    }
    str.push_back('!');
    // cout << str << endl;
    for (int i = 2; i < static_cast<int>(str.size()); i++) {
        if (i <= mr) {
            p[i] = min(p[mid * 2 - i], mr - i + 1);
        } else {
            p[i] = 1;
        }
        while (str[i - p[i]] == str[i + p[i]]) {
            ++p[i];
        }
        if (i + p[i] > mr) {
            mr = i + p[i] - 1;
            mid = i;
        }
        if (~(i & 1)) {
            cerr << p[i] << ' ';
        }
        em[i - p[i] + 1] = max(em[i - p[i] + 1], p[i] - 1);
        sm[i + p[i] - 1] = max(sm[i + p[i] - 1], p[i] - 1);
    }
    cerr << endl;
    for (int i = 2; i < static_cast<int>(str.size()); i += 2) {
        em[i] = max(em[i], em[i - 2] - 2);
        cerr << em[i] << ' ';
    }
    cerr << endl;
    for (int i = static_cast<int>(str.size()) - 1; i >= 2; i -= 2) {
        sm[i] = max(sm[i], sm[i + 2] - 2);
        cerr << sm[i] << ' ';
    }
    cerr << endl;
    for (int i = 2; i < static_cast<int>(str.size()); i += 2) {
        if (em[i] && sm[i]) {
            ans = max(ans, em[i] + sm[i]);
        }
    }
    cout << ans << endl;
    return 0;
}