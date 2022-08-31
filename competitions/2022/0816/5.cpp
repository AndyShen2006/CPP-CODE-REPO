#include <bits/stdc++.h>

using namespace std;

vector<int> skills[100001];
bool isValid[100001];
int n, ans;

void dfs(int level)
{
    bool sign = false;
    for (auto it : skills[level]) {
        if (!isValid[it]) {
            isValid[it] = true;
            dfs(level + 1);
            sign = true;
            isValid[it] = false;
        }
    }
    if (sign) {
        ans = max(ans, level);
    }
}

int main()
{
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        skills[b].emplace_back(c);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}