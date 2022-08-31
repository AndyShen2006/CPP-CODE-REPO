#include <bits/stdc++.h>

using namespace std;

struct Node {
    int a, b;
} nodes[50010];

inline bool cmp(Node& a, Node& b)
{
    return a.a == b.a ? a.b < b.b : a.a > b.a;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].b;
    }
    stable_sort(nodes + 1, nodes + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += nodes[i].b;
    }
    cout << ans << endl;
    return 0;
}