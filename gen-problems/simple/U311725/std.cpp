#include <bits/stdc++.h>

using namespace std;

struct Node {
    int l = 0, r = 0;
    mutable int val = 0;
    Node(int a, int b, int c)
    {
        l = a;
        r = b;
        val = c;
    }
    explicit Node(int a)
    {
        l = a;
    }
    bool operator<(const Node& a) const
    {
        return l < a.l;
    }
};

set<Node> ct;

typedef set<Node>::iterator tit;

tit split(int pos)
{
    auto it = ct.lower_bound(Node(pos));
    if (it != ct.end() && it->l == pos) {
        return it;
    }
    --it;
    int l = it->l, r = it->r;
    int val = it->val;
    ct.erase(it);
    ct.insert(Node(l, pos - 1, val));
    return ct.insert(Node(pos, r, val)).first;
}

void assign(int l, int r, int val)
{
    auto it2 = split(r + 1), it1 = split(l);
    ct.erase(it1, it2);
    ct.insert(Node(l, r, val));
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    ct.insert({ 0, n - 1, 0 });
    int fir = (p + q) % n, sec = fir;
    int s = max(0, (m / n - 1) * n);
    for (int i = s + 1; i <= m; i++) {
        if (fir > sec) {
            assign(sec, fir, i);
        } else {
            assign(fir, sec, i);
        }
        fir = (fir + p) % n;
        sec = (sec + q) % n;
    }
    for (auto it : ct) {
        for (int i = it.l; i <= it.r; i++) {
            cout << it.val << ' ';
        }
    }
    cout << endl;
    return 0;
}