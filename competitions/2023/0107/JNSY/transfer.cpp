#include <bits/stdc++.h>

using namespace std;

map<int, map<string, int>, greater<>> stars;
bool vis[1000010];
map<int, string> output;

int main()
{
    // freopen("data/transfer3.in", "r", stdin);
    // freopen("data/transfer3.chk", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string ts;
    int tm;
    for (int i = 1; i <= n; i++) {
        cin >> ts >> tm;
        stars[tm].insert({ ts, i });
    }
    int l = 1, r = 0;
    bool flag = false;
    for (const auto& it1 : stars) {
        r += it1.second.size();
        for (const auto& it2 : it1.second) {
            if (!vis[it2.second] && (l <= it2.second && it2.second <= r)) {
                vis[it2.second] = true;
                flag = true;
                output.insert({ it2.second, it2.first });
            }
        }
        l = r + 1;
    }
    for (const auto& it : output) {
        cout << it.second << endl;
    }
    if (!flag) {
        cout << "Washboard" << endl;
    }
    return 0;
}