#include <bits/stdc++.h>

using namespace std;

struct s {
    string str[3];
};
s strs[1001];
inline bool equal(s& a, s& b)
{
    return a.str[0] == b.str[0] && a.str[1] == b.str[1] && a.str[2] == b.str[2];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> strs[i].str[0] >> strs[i].str[1] >> strs[i].str[2];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(strs[i].str, strs[i].str + 3);
        //cout << strs[i].str[0] << ' ' << strs[i].str[1] << ' ' << strs[i].str[2] << endl;
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (equal(strs[i], strs[j])) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

/*
6
BESSIE ELSIE MATILDA
FRAN BESSIE INGRID
BESSIE ELSIE MATILDA
MATILDA INGRID FRAN
ELSIE BESSIE MATILDA
ELSIE MATILDA BESSIE

1
ELSIE MATILDA BESSIE
*/