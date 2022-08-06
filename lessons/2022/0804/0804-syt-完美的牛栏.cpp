#include <bits/stdc++.h>

using namespace std;
int G[1010][1010];
bool used[1010];
int match[1010];
int r, a, t;
bool found(int x)
{
    for (int i = 1; i <= a; i++) {
        if (G[x][i] && !used[i]) {
            used[i] = true;
            if (match[i] == 0 || found(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> r >> a;
    int s, node;
    for (int i = 1; i <= r; i++) {
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> node;
            G[i][node] = 1;
        }
    }
    int sum = 0;
    for (int i = 1; i <= r; i++) {
        memset(used, 0, sizeof(used));
        if (found(i)) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}