#include <bits/stdc++.h>

using namespace std;

struct Road {
    int from, to;
    int time;
    Road(int x, int y, int t)
    {
        from = x;
        to = y;
        time = t;
    };
    bool operator>(const Road& rhs) const
    {
        return this->time > rhs.time;
    }
    void show() const
    {
        printf("from:%d,to:%d,time:%d\n", from, to, time);
    }
};

priority_queue<Road, vector<Road>, greater<Road>> P;

int cnt;
int par[1000010];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findpar(int n)
{
    if (par[n] == n) {
        return n;
    } else {
        return par[n] = findpar(par[n]);
    }
}

void unite(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    // cout << a << ' ' << b << endl;
    if (a == b) {
        return;
    }
    par[a] = b;
    // cout << "count--!" << endl;
    cnt--;
}

int main()
{
    // freopen("data/p1111.in", "r", stdin);
    int n, m;
    int x, y, t;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> t;
        P.push(Road(x, y, t));
    }
    cnt = n;
    while (!P.empty()) {
        Road r = P.top();
        P.pop();
        unite(r.from, r.to);
        // r.show();
        if (cnt == 1) {
            cout << r.time << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
    return 0;
}