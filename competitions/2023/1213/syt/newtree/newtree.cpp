#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;
vector<int> T[MAX_N];
int par[MAX_N], dep[MAX_N];
priority_queue<int> top3;
void push(int x)
{
    top3.push(x);
    if (top3.size() > 3) {
        top3.pop();
    }
}

void dfs(int x)
{
    for (auto it : T[x]) {
        if (it == par[x]) {
            continue;
        }
        dep[it] = dep[x] + 1;
        par[it] = x;
        push(dep[it]);
        dfs(it);
    }
}

int main()
{
    freopen("newtree.in", "r", stdin);
    freopen("newtree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    if (n == 2) {
        cout << 0 << endl;
    } else {
        dfs(1);
        int t2, t3;
        top3.pop();
        t2 = top3.top();
        top3.pop();
        t3 = top3.top();
        top3.pop();
        cout << abs(t2 - t3) << endl;
    }
    return 0;
}