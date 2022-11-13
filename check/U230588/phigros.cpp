#include <bits/stdc++.h>

using namespace std;

struct music {
    string name;
    double rks {}, level {};
    music() = default;
    music(string n, double l, double acc)
    {
        name = std::move(n);
        level = l;
        rks = ((acc - 55.0) / 45.0) * ((acc - 55.0) / 45.0) * l;
        rks = floor((rks + 0.005) * 100) / 100;
    }
    inline bool operator>(const music& rhs) const
    {
        // cout << rks << ' ' << rhs.rks << endl;
        // cout << level << ' ' << rhs.level << endl;
        return rks == rhs.rks ? level > rhs.level : rks > rhs.rks;
    }
} rks[1001];

int main()
{
    freopen("data/phigros2.in", "r", stdin);
    freopen("data/phigros2.out", "w", stdout);
    int n;
    cin >> n;
    string name;
    double level, acc;
    for (int i = 1; i <= n; i++) {
        cin >> name >> level >> acc;
        rks[i] = music(name, level, acc);
    }
    sort(rks + 1, rks + n + 1, greater<music>());
    double arrrks = 0;
    for (int i = 1; i <= 10; i++) {
        arrrks += rks[i].rks;
    }
    arrrks /= 10;
    cout << floor((arrrks + 0.005) * 100) / 100 << endl;
    for (int i = 1; i <= n; i++) {
        cout << rks[i].name << ' ' << rks[i].rks << endl;
    }
    return 0;
}