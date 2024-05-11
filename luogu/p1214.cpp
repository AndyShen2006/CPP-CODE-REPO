#include <bits/stdc++.h>

using namespace std;

set<int> lis;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            lis.insert(i * i + j * j);
        }
    }
    // for (auto it : lis) {
    //     cerr << it << ' ';
    // }
    // cerr << endl;
    bool flag = false;
    if (n == 3) {
        for (int j = 1; j <= (m * m * 2); j++) {
            for (int i = 0; i <= (m * m * 2); i++) {
                if (lis.find(i) != lis.end() && lis.find(i + j) != lis.end() && lis.find(i + j + j) != lis.end()) {
                    cout << i << ' ' << j << endl;
                }
            }
        }
        exit(0);
    }
    for (int b = 4; b <= (m * m * 2) / (n - 1); b += 4) {
        for (int a = 0; a <= m * m * 2 - (n - 1) * b; a++) {
            int cnt = 0;
            for (int i = 0; a + i * b <= m * m * 2; i++) {
                if (lis.find(a + b * i) == lis.end()) {
                    break;
                }
                cnt++;
            }
            // cout << a << ' ' << b << ' ' << cnt << endl;
            if (cnt >= n) {
                flag = true;
                cout << a << ' ' << b << endl;
            }
        }
    }
    if (!flag) {
        cout << "NONE" << endl;
    }
    return 0;
}