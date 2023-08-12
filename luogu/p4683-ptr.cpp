#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool ef = false;
    bool flag = false;
    Node* nxt[26] {};
    Node* par;
    Node()
    {
        par = nullptr;
        fill(nxt, nxt + 26, nullptr);
    }
};

vector<char> stk;

Node* root = new Node;
Node* mdpn;
int maxlen, maxlen2;

void insert(const string& str)
{
    Node* p = root;
    for (auto it : str) {
        if (p->nxt[it - 'a'] == nullptr) {
            p->nxt[it - 'a'] = new Node;
            p->nxt[it - 'a']->par = p;
        }
        p = p->nxt[it - 'a'];
    }
    p->ef = true;
    if (str.size() > maxlen) {
        maxlen = str.size();
        mdpn = p;
    }
}

void re_traverse(Node* cur)
{
    if (cur == root) {
        return;
    }
    cur->flag = true;
    re_traverse(cur->par);
}

int cnt = 0, n;

void traverse(Node* cur)
{
    if (cur->ef) {
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
        if (cur->nxt[i] != nullptr && !cur->nxt[i]->flag) {
            // cout << char('a' + i) << endl;
            stk.push_back('a' + i);
            traverse(cur->nxt[i]);
            stk.push_back('-');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cur->nxt[i] != nullptr && cur->nxt[i]->flag) {
            stk.push_back('a' + i);
            traverse(cur->nxt[i]);
            stk.push_back('-');
        }
    }
}

int main()
{
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