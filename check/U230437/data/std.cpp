#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
#define ll long long
using namespace std;
struct node {
    ll to, v;
    bool operator<(const node& x) const
    {
        return v > x.v;
    }
} u;
ll n, m, q, a, b;
vector<node> p[3005];
vector<node> w[3005];
priority_queue<node> t;
ll f1[3005], f2[3005];
bool v1[3005], v2[3005];
void dij()
{
    t.push((node) { 1, 0 });
    while (!t.empty()) {
        u = t.top();
        t.pop();
        if (v1[u.to])
            continue;
        v1[u.to] = 1;
        for (int i = 0; i < p[u.to].size(); i++) {
            if (f1[p[u.to][i].to] > u.v + p[u.to][i].v) {
                f1[p[u.to][i].to] = u.v + p[u.to][i].v;
                if (!v1[p[u.to][i].to])
                    t.push((node) { p[u.to][i].to, f1[p[u.to][i].to] });
            }
        }
    }
    t.push((node) { 1, 0 });
    while (!t.empty()) {
        u = t.top();
        t.pop();
        if (v2[u.to])
            continue;
        v2[u.to] = 1;
        for (int i = 0; i < w[u.to].size(); i++) {
            if (f2[w[u.to][i].to] > u.v + w[u.to][i].v) {
                f2[w[u.to][i].to] = u.v + w[u.to][i].v;
                if (!v2[w[u.to][i].to])
                    t.push((node) { w[u.to][i].to, f2[w[u.to][i].to] });
            }
        }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &a, &u.to, &u.v);
        p[a].push_back(u);
        swap(a, u.to);
        w[a].push_back(u);
    }
    for (int i = 2; i <= n; i++)
        f1[i] = f2[i] = inf;
    dij();
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld", &a, &b);
        if (f1[b] < inf && f2[a] < inf)
            printf("%lld\n", f1[b] + f2[a]);
        else
            printf("-1\n");
    }
    return 0;
}
