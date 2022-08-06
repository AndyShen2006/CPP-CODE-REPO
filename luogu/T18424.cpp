#include <bits/stdc++.h>

using namespace std;
int r, a;
int G[110][110];
bool used[110];
int match[110];
bool found(int x)
{
    for (int i = 1; i <= r; i++) {
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
inline bool getpos(int r, int c)
{
    return r * r + c;
}

int main()
{
    cin >> r >> a;
    // Generate graph
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= r; j++) {
            if (i + 1 <= r) {
                G[getpos(i, j)][getpos(i + 1, j)] = 1;
            }
            if (j + 1 <= r) {
                G[getpos(i, j)][getpos(i, j + 1)] = 1;
            }
            if (i - 1 >= 1) {
                G[getpos(i, j)][getpos(i - 1, j)] = 1;
            }
            if (j - 1 >= 1) {
                G[getpos(i, j)][getpos(i, j - 1)] = 1;
            }
        }
    }
    int x, y;
    for (int i = 1; i <= a; i++) {
        cin >> x >> y;
        fill(G[getpos(x, y)] + 1, G[getpos(x, y)] + r + 1, 0);
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