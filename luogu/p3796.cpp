#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100;
int nxt[MAX_N], trie[MAX_N][26], alloc, cnt[MAX_N];

void insert(const string& str)
{
    int cur = 0;
    for (auto it : str) {
        if (!trie[cur][it - 'a']) {
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
        if (it) {
            Q.push(it);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        for (int i = 0; i < 26; i++) {
            int v = trie[u][i];
            if (v) {
                nxt[v] = trie[nxt[u]][i];
                Q.push(v);
            } else {
                trie[u][i] = trie[nxt[u]][i];
            }
        }
    }
}

int main()
{

    return 0;
}