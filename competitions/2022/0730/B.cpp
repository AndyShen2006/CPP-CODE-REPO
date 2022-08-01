#include <bits/stdc++.h>

using namespace std;

map<int, set<int, greater<int>>, greater<int>> bipos; // bit,pos
bool ans[65537]; // 0->can't read;1->use or;2->use xor;
int rea[25001];

int main()
{
    // freopen("data/B3.in", "r", stdin);
    int s, t;
    cin >> s >> t;
    int n, x, y, tb, maxb;
    string sym;
    for (int k = 1; k <= t; k++) {
        cin >> n >> x >> y;
        maxb = 0;
        sym.clear();
        bipos.clear();
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            cin >> tb;
            bipos[tb].insert(i);
            maxb = max(maxb, tb);
            rea[i - 1] = tb;
        }
        for (int i = 1; i < n; i++) {
            sym.push_back('^');
        }
        for (const auto& it : bipos) {
            // cout << it.first << ' ' << it.second.size() << endl;
            if (it.second.size() % 2 == 0 && y > 0) {
                sym[*it.second.begin() - 2] = '|';
                y--;
            }
            // cout << sym << endl;
        }
        // cout << y << endl;
        for (auto i = sym.size() - 1; i >= 0; i--) {
            if (y <= 0) {
                break;
            } else if (sym[i] != '|') {
                sym[i] = '|';
                y--;
            }
        }
        ans[rea[0]] = true;
        for (int i = 0; i < n - 1; i++) {
            if (sym[i] == '^') {
                ans[rea[i + 1]] ^= true;
            } else {
                ans[rea[i + 1]] |= true;
            }
        }
        bool isvalid = true, isoutput = false;
        for (int i = maxb; i >= 0; i--) {
            if (ans[i] == 0 && isvalid) {
                continue;
            }
            isvalid = false;
            isoutput = true;
            cout << ans[i];
        }
        if (!isoutput) {
            cout << 0;
        }
        cout << endl;
        cout << sym << endl;
    }
    return 0;
}