#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct Node {
    ll w, c;
    bool operator<(const Node& rhs) const
    {
        return this->c < rhs.c;
    }
};

set<Node> fs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int op;
    Node tmp = {};
    while (true) {
        cin >> op;
        if (op == 1) {
            ll w, c;
            cin >> w >> c;
            tmp = { w, c };
            fs.insert(tmp);
        } else if (op == 2 && !fs.empty()) {
            fs.erase(--fs.end());
        } else if (op == 3 && !fs.empty()) {
            fs.erase(fs.begin());
        } else if (op == -1) {
            ll ans1 = 0, ans2 = 0;
            for (auto it : fs) {
                ans1 += it.w;
                ans2 += it.c;
            }
            cout << ans1 << ' ' << ans2 << endl;
            exit(0);
        }
    }
    return 0;
}