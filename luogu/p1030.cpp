#include <bits/stdc++.h>

using namespace std;

string past;
string pre, mid;

void dfs(string m, string p) // NOLINT
{
    char root = p[p.size() - 1];
    int size = m.find(root); // NOLINT
    pre.push_back(root);
    if (p.size() <= 1) {
        return;
    }
    if (size > 0)
        dfs(m.substr(0, size), p.substr(0, size));
    if (p.size() - size - 1 > 0)
        dfs(m.substr(size + 1, m.size() - size - 1), p.substr(size, p.size() - size - 1));
}

int main()
{
    cin >> mid >> past;
    dfs(mid, past);
    cout << pre << endl;
    return 0;
}