#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e5 + 10;
vector<int> stk, ans, tmp;
int a[MAX_N];
bool vis[MAX_N];

int main()
{
    // freopen("data/p3460a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (vis[a[i]]) {
            while (stk.back() != a[i]) {
                ans.push_back(int(stk.size()));
                tmp.push_back(stk.back());
                stk.pop_back();
            }
            stk.pop_back();
            while (!tmp.empty()) {
                stk.push_back(tmp.back());
                tmp.pop_back();
            }
            vis[a[i]] = false;
        } else {
            stk.push_back(a[i]);
            vis[a[i]] = true;
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}