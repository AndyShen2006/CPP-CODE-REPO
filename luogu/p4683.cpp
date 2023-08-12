#include <bits/stdc++.h>

using namespace std;

bool efs[500010];
bool flag[500010];
int par[500010];
int trie[500010][26];

vector<char> stk;

int root = 0;
int alloc = 0;
int mdpn;
int maxlen, maxlen2;

void insert(const string& str)
{
    int p = root;
    for (auto it : str) {
        if (trie[p][it - 'a'] == -1) {
            trie[p][it - 'a'] = ++alloc;
            par[alloc] = p;
        }
        p = trie[p][it - 'a'];
    }
    efs[p] = true;
    if (str.size() > maxlen) {
        maxlen = str.size();
        mdpn = p;
    }
}

void re_traverse(int cur)
{
    if (cur == root) {
        return;
    }
    flag[cur] = true;
    re_traverse(par[cur]);
}

int cnt = 0, n;

void traverse(int cur)
{
    if (efs[cur]) {
        stk.push_back('P');
        cnt++;
    }

    if (cnt == n) {
        cout << stk.size() << endl;
        for (auto it : stk) {
            cout << it << endl;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (trie[cur][i] != -1 && !flag[trie[cur][i]]) {
            // cout << char('a' + i) << endl;
            stk.push_back('a' + i);
            traverse(trie[cur][i]);
            stk.push_back('-');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (trie[cur][i] != -1 && flag[trie[cur][i]]) {
            stk.push_back('a' + i);
            traverse(trie[cur][i]);
            stk.push_back('-');
        }
    }
}

int main()
{
    memset(trie, -1, sizeof trie);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        insert(str);
    }
    stk.reserve(60000);
    re_traverse(mdpn);
    traverse(root);
    return 0;
}