#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;
int flag[MAX_N], pre[MAX_N];
int note[3];
int sum;
string s;
#define DEBUG 0

int check(int pos)
{
    memset(note, 0, sizeof(note));
    note[s[pos - 2] - 'a']++;
    note[s[pos - 1] - 'a']++;
    note[s[pos] - 'a']++;
    return *max_element(note, note + 3) - 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin >> s;
    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2) {
        if (s[0] == s[1]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    for (int i = 2; i < n; i++) {
        flag[i] = check(i);
    }
#if DEBUG
    for (int i = 0; i < n; i++) {
        cout << flag[i] << ' ';
    }
    cout << endl;
#endif
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + flag[i - 1];
    }
#if DEBUG
    for (int i = 1; i <= n; i++) {
        cout << pre[i] << ' ';
    }
    cout << endl;
#endif
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l] << endl;
    }
    return 0;
}