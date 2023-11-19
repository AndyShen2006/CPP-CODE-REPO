#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;
set<int> T[MAX_N];
set<int> leaves[MAX_N];
struct Cmp {
    bool operator()(const int& lhs, const int& rhs) const
    {
        return leaves[lhs].size() == leaves[rhs].size() ? lhs > rhs : leaves[lhs].size() > leaves[rhs].size();
    }
};
set<int, Cmp> curT;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n - 1; i++) {
            int x, y;
            cin >> x >> y;
            T[x].insert(y);
            T[y].insert(x);
        }
        for (int i = 1; i <= n; i++) {
            if (T[i].size() == 1) {
                leaves[*T[i].begin()].insert(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            curT.insert(i);
        }
        int ans = 0;
        while (true) {
            int u = *curT.begin();
            if (int(leaves[u].size()) < k) {
                break;
            }
            for (int i = 0; i < k; i++) {
                int leaf = *leaves[u].begin();
                T[leaf].erase(u);
                T[u].erase(leaf);
                curT.erase(u);
                curT.erase(leaf);
                leaves[u].erase(leaf);
                if (leaves[leaf].count(u)) { // 2 points, a--b, a is b's leaf and b is a's leaf
                    leaves[leaf].erase(u);
                }
                if (T[u].size() == 1) {
                    int v = *T[u].begin();
                    curT.erase(v);
                    leaves[v].insert(u);
                    curT.insert(v);
                }
                curT.insert(u);
                curT.insert(leaf);
            }
            ans++;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            T[i].clear();
            leaves[i].clear();
        }
        curT.clear();
    }
    return 0;
}