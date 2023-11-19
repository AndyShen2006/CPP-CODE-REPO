#include <bits/stdc++.h>

using namespace std;

bool vis[10010];

string toBool(int a)
{
    string ans;
    while (a > 0) {
        ans.push_back('0' + (a & 1));
        a >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    freopen("data/cf1338c-table1.out", "w", stdout);
    int mn = 1000;
    for (int i = 1; i <= mn; i++) {
        for (int j = i + 1; j <= mn; j++) {
            for (int k = j + 1; k <= mn; k++) {
                if (vis[i] || vis[j] || vis[k]) {
                    continue;
                }
                if (i ^ j ^ k) {
                    continue;
                }
                vis[i] = vis[j] = vis[k] = true;
                cout << i << ' ' << toBool(i) << endl
                     << j << ' ' << toBool(j) << endl
                     << k << ' ' << toBool(k) << endl;
                cout << endl;
            }
        }
    }

    return 0;
}