#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// Has been accepted on test 1
set<int> Container;

int main()
{
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        char c;
        int x;
        cin >> c >> x;
        switch (c) {
        case 'A':
            if (Container.find(x) != Container.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                Container.insert(x);
            }
            break;
        case 'D':
            if (Container.find(x) == Container.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                Container.erase(x);
            }
            break;
        case 'Q':
            if (Container.find(x) == Container.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}