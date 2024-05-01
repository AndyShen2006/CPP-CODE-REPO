#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int ta;
        cin >> ta;
        if (mp.find(ta) == mp.end()) {
            mp[ta] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        int tb;
        cin >> tb;
        if (mp.find(tb) == mp.end()) {
            cout << -1 << endl;
        } else {
            cout << mp[tb] << endl;
        }
    }
    return 0;
}