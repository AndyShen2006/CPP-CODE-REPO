#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 22000010;

int p[MAX_N];
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
        ans = max(ans, p[i]);
    }
    cout << ans - 1 << endl;
    return 0;
}