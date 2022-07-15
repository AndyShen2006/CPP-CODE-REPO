#include <bits/stdc++.h>

using namespace std;

string past;
string pre, mid;

void dfs(string p, string m) // NOLINT
{
    char root = p[0];
    int size = m.find(root); // NOLINT
    if (p.size() <= 1) {
        past.push_back(root);
        return;
    }
    if (size > 0)
        dfs(p.substr(1, size), m.substr(0, size));
    if (p.size() - size - 1 > 0)
        dfs(p.substr(size + 1, p.size() - size - 1), m.substr(size + 1, m.size() - size - 1));
    past.push_back(root);
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> mid >> pre;
    dfs(pre, mid);
    cout << past << endl;
    return 0;
}