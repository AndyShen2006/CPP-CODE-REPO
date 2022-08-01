#include <bits/stdc++.h>

using namespace std;

int pos;
string pre, in, post;

void rec(int l, int r)
{
    if (l >= r) {
        return;
    }
    char root = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m + 1, r);
    post.push_back(root);
}

void solve()
{
    pos = 0;
    rec(0, pre.size());
}

int main()
{
    cin >> pre >> post;
    solve();
    return 0;
}