#include <bits/stdc++.h>

using namespace std;

bool seq[200000];

int count(int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += seq[i];
    }
    return cnt;
}

int main()
{
    freopen("gh.in", "r", stdin);
    freopen("gh.out", "w", stdout);
    int n;
    string str;
    cin >> n >> str;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'G') {
            seq[pos++] = ((i + 1) & 1);
        }
    }
    int ans = 0;
    for (int i = pos; i >= 1; i--) {
        int s = count(i);
        int rs = i - s;
        // cout << s << ' ' << rs << endl;
        if (s > rs) {
            for (int j = 0; j < i; j++) {
                seq[j] = !seq[j];
            }
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}