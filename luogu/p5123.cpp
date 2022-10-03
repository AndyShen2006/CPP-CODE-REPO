#include <bits/stdc++.h>

using namespace std;

map<int, bitset<50001>> type;

struct cow {
    int a[6];
} cows[50001];

int main()
{
    // freopen("data/p5123a.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> cows[i].a[j];
            type[cows[i].a[j]].set(i, true);
        }
    }
    int ans = 0;
    bitset<50001> check;
    for (int i = 0; i < n; i++) {
        check.reset();
        for (int j = 1; j <= 5; j++) {
            check |= type[cows[i].a[j]];
            // cout << type[cows[i].a[j]] << endl;
        }
        // cout << check << endl;
        ans += n - check.count();
        // cout << check.count() << endl;
    }
    cout << (ans >> 1) << endl;
    return 0;
}