#include <bits/stdc++.h>

using namespace std;

map<int, bitset<50001> > type;

struct cow {
    int a[11];
} cows[50001];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cows[i].a[j];
            type[cows[i].a[j]].set(i, true);
        }
    }
    int del = 0, add = 0;
    bitset<50001> check;
    for (int i = 0; i < m; i++) {
        check.reset();
        for (int j = 1; j <= n; j++) {
            check ^= type[cows[i].a[j]];
            // cout << type[cows[i].a[j]] << endl;
        }
        // cout << check << endl;
        del += m - 1 - check.count();
        add += check.count();
        if (n % 2 == 1) {
            del++;
    	}
        // cout << add << ' ' << del << endl;
    }
    cout << (add - del) /2 << endl;
    return 0;
}
