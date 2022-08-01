#include <bits/stdc++.h>
using namespace std;

struct song {
    string s;
    double level, acc, rks;
} a[1005];

int n;
double maxShouValue = 0;
double totalrks = 0;

bool cmp(song x, song y)
{
    if (x.rks == y.rks)
        return x.level > y.level;
    return x.rks > y.rks;
}

int main()
{

    freopen("data/phigros2.in", "r", stdin);
    freopen("data/phigros2.ans", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].level >> a[i].acc;
        if (a[i].acc == 100) {
            a[i].rks = a[i].level;
            maxShouValue = max(a[i].level, maxShouValue);
        } else {
            a[i].rks = ((a[i].acc - 55) / 45) * ((a[i].acc - 55) / 45) * a[i].level;
        }
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= 9; i++)
        totalrks += a[i].rks;
    totalrks += maxShouValue;
    totalrks /= 10;
    cout << floor((totalrks + 0.005) * 100) / 100 << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i].s << ' ' << floor((a[i].rks + 0.005) * 100) / 100 << endl;
    }
    return 0;
}
