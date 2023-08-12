#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* nxt[2] = { nullptr, nullptr };
    Node() = default;
    int cnt = 0, ecnt = 0;
};

Node* root = new Node;

void insert(const vector<int>& lis)
{
    Node* p = root;
    for (auto it : lis) {
        if (p->nxt[it] == nullptr) {
            p->nxt[it] = new Node;
        }
        p = p->nxt[it];
        p->cnt++;
    }
    p->ecnt++;
}

void debug(Node* x, int dep)
{
    if (x->nxt[0] != nullptr) {
        printf("depth:%d, type:0, cnt:%d, ecnt:%d\n", dep + 1, x->nxt[0]->cnt, x->nxt[0]->ecnt);
        debug(x->nxt[0], dep + 1);
    }
    if (x->nxt[1] != nullptr) {
        printf("depth:%d, type:1, cnt:%d, ecnt:%d\n", dep + 1, x->nxt[1]->cnt, x->nxt[1]->ecnt);
        debug(x->nxt[1], dep + 1);
    }
}

void check(const vector<int>& lis)
{
    Node* p = root;
    int ans = 0;
    for (auto it : lis) {
        if (p->nxt[it] == nullptr) {
            cout << ans << endl;
            return;
        }
        p = p->nxt[it];
        ans += p->ecnt;
    }
    cout << p->cnt + ans - p->ecnt << endl;
}

int main()
{
    // freopen("data/P2922_2.in", "r", stdin);
    // freopen("data/P2922_2.chk", "w", stdout);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        vector<int> tmp;
        tmp.clear();
        for (int j = 1; j <= k; j++) {
            int b;
            cin >> b;
            tmp.push_back(b);
        }
        insert(tmp);
    }
    // debug(root, 0);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> tmp;
        tmp.clear();
        for (int j = 1; j <= k; j++) {
            int c;
            cin >> c;
            tmp.push_back(c);
        }
        check(tmp);
    }
    return 0;
}