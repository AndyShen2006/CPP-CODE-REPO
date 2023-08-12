#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* child[26] {};
    bool flag = false;
    Node()
    {
        memset(child, 0, sizeof(child));
    }
    set<int> nums;
};

Node* root = new Node;

void insert(const string& word, int num)
{
    Node* p = root;
    for (auto it : word) {
        if (p->child[it - 'a'] == nullptr) {
            p->child[it - 'a'] = new Node;
        }
        p = p->child[it - 'a'];
    }
    p->flag = true;
    p->nums.insert(num);
}

void check(const string& str)
{
    Node* p = root;
    for (auto it : str) {
        if (p->child[it - 'a'] == nullptr) {
            cout << endl;
            return;
        }
        p = p->child[it - 'a'];
    }
    for (auto it : p->nums) {
        cout << it << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int l;
    for (int i = 1; i <= n; i++) {
        cin >> l;
        for (int j = 1; j <= l; j++) {
            string word;
            cin >> word;
            insert(word, i);
        }
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        check(str);
    }
    return 0;
}