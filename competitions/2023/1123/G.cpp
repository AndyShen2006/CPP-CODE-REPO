#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 256;
pair<char, char> G[MAX_N];

char solve(const string& pre, const string& mid)
{
    if (pre.empty()) {
        return 0;
    }
    char rt = pre[0];
    if (pre.size() <= 1) {
        return rt;
    }
    int loc = mid.find(rt);
    G[rt].first = solve(pre.substr(1, loc), mid.substr(0, loc));
    G[rt].second = solve(pre.substr(loc + 1, pre.size() - loc - 1), mid.substr(loc + 1, mid.size() - loc - 1));
    return rt;
}

void post_find(char x)
{
    if (G[x].first) {
        post_find(G[x].first);
    }
    if (G[x].second) {
        post_find(G[x].second);
    }
    cout << x;
}

int main()
{
    string pre, mid;
    cin >> pre >> mid;
    solve(pre, mid);
    post_find(pre[0]);
    cout << endl;
    return 0;
}