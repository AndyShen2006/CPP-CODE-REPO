#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000010;

int nxt[MAX_N], trie[MAX_N][26], cnt[MAX_N], alloc;

void insert(const string& str)
{
    int cur = 0;
    for (auto it : str) {
        if (trie[cur][it - 'a'] == 0) {
            trie[cur][it - 'a'] = ++alloc;
        }
        cur = trie[cur][it - 'a'];
    }
    cnt[cur]++;
}

void build()
{
    queue<int> Q;
    for (auto it : trie[0]) {
        if (it != 0) {
            Q.push(it);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < 26; i++) {
            int v = trie[u][i];
            if (v != 0) {
                nxt[v] = trie[nxt[u]][i];
                Q.push(v);
            } else {
                trie[u][i] = trie[nxt[u]][i];
            }
        }
    }
}

int query(const string& str)
{
    int ans = 0;
    int cur = 0;
    for (auto it : str) {
        cur = trie[cur][it - 'a'];
        for (int j = cur; j && ~cnt[j]; j = nxt[j]) {
            ans += cnt[j];
            cnt[j] = -1;
        }
    }
    return ans;
}

int main()
{
    // freopen("data/P3808_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string ts;
        cin >> ts;
        insert(ts);
    }
    build();
    string t;
    cin >> t;
    cout << query(t) << endl;
    return 0;
}