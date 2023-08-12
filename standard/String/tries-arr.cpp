#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;

int trie[MAX_N][26];
bool final[MAX_N];
set<int> nums[MAX_N];
int pos;

void insert(const string& str, const int num)
{
    int cur = 0;
    for (auto it : str) {
        if (trie[cur][it - 'a'] == 0) {
            trie[cur][it - 'a'] = ++pos;
        }
        cur = trie[cur][it - 'a'];
    }
    final[cur] = true;
    nums[cur].insert(num);
}

void check(const string& str)
{
    int cur = 0;
    for (auto it : str) {
        if (trie[cur][it - 'a'] == 0) {
            cout << endl;
            return;
        }
        cur = trie[cur][it - 'a'];
    }
    for (auto it : nums[cur]) {
        cout << it << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            string str;
            cin >> str;
            insert(str, i);
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