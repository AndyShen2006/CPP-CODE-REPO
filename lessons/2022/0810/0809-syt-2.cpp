#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[10000000];

inline void qread(ll& ans)
{
    ans = 0;
    static char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
}

struct Node {
    ll l, r;
} tree[10000000];
ll n;

stack<ll> st;
ll root; //处理出根，用来遍历
inline void build()
{
    ll last = 1; //记录最后一个出队的节点
    st.push(1);
    for (int i = 2; i <= n; i++) {
        while (!st.empty() && a[i] < a[st.top()]) { //维护单调性
            last = st.top();
            st.pop();
        }
        if (st.empty()) {
            tree[i].l = last;
        } else {
            tree[i].l = tree[st.top()].r;
            tree[st.top()].r = i;
        }
        st.push(i);
    }
}

int main()
{
    qread(n);
    for (int i = 1; i <= n; i++) {
        qread(a[i]);
    }
    build();
    ll ans1 = 0, ans2 = 0;
    for (ll i = 1; i <= n; i++) {
        ans1 ^= i * (tree[i].l + 1);
        ans2 ^= i * (tree[i].r + 1);
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}