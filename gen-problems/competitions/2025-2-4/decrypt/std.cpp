#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10000;
int cnt[256], rk[MAX_N], pos[MAX_N];

int main()
{
    string src;
    cin >> src;
    int n = int(src.size());
    for (char c : src) {
        cnt[c]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        pos[--cnt[src[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
        rk[pos[i]] = i;
    }
    string ans;
    int idx = pos[0];
    for (int i = 0; i < n; i++) {
        ans.push_back(src[idx]);
        idx = rk[idx];
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    cout << ans << endl;
}