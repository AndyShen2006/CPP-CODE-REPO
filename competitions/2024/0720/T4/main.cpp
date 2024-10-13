#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
int pre[MAX_N];
string spre[MAX_N];
int trie[MAX_N][2];
int pos;

void insert(const string& str, const int num)
{
    int cur = 0;
    for (auto it : str) {
        if (trie[cur][it - '0'] == 0) {
            trie[cur][it - '0'] = ++pos;
        }
        cur = trie[cur][it - '0'];
    }
}

int check(const string& str)
{
    int cur = 0;
    for (auto it : str) {
        if (trie[cur][(it - '0') ^ 1] == 0) {
            return 0;
        }
        cur = trie[cur][it - '0'];
    }
}

int main()
{
    int n, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        pre[i] = pre[i - 1] ^ tmp;
        string st;
        int it = pre[i];
        while (it > 0) {
            st.push_back('0' + (it & 1));
            it >>= 1;
        }
        while (st.size() <= 32) {
            st.push_back('0');
        }
        reverse(st.begin(), st.end());
        spre[i] = st;
    }
    return 0;
}