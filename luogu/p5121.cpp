#include <bits/stdc++.h>

using namespace std;

int mat[110][15];
bool vis[110][15];
int n, k;

void show()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int check(int r, int c)
{
    int ans = 0;
    if (mat[r][c] != 0) {
        if (mat[r + 1][c] == mat[r][c] && !vis[r + 1][c]) {
            vis[r + 1][c] = true;
            ans += check(r + 1, c);
        }
        if (mat[r - 1][c] == mat[r][c] && !vis[r - 1][c]) {
            vis[r - 1][c] = true;
            ans += check(r - 1, c);
        }
        if (mat[r][c + 1] == mat[r][c] && !vis[r][c + 1]) {
            vis[r][c + 1] = true;
            ans += check(r, c + 1);
        }
        if (mat[r][c - 1] == mat[r][c] && !vis[r][c - 1]) {
            vis[r][c - 1] = true;
            ans += check(r, c - 1);
        }
        return ans + 1;
    }
    return 0;
}

void del(int r, int c)
{
    vis[r][c] = true;
    if (mat[r][c] != 0) {
        if (mat[r + 1][c] == mat[r][c] && !vis[r + 1][c]) {
            del(r + 1, c);
            mat[r + 1][c] = 0;
        }
        if (mat[r - 1][c] == mat[r][c] && !vis[r - 1][c]) {
            del(r - 1, c);
            mat[r - 1][c] = 0;
        }
        if (mat[r][c + 1] == mat[r][c] && !vis[r][c + 1]) {
            del(r, c + 1);
            mat[r][c + 1] = 0;
        }
        if (mat[r][c - 1] == mat[r][c] && !vis[r][c - 1]) {
            del(r, c - 1);
            mat[r][c - 1] = 0;
        }
    }
}

void clear()
{
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= 10; b++) {
            vis[a][b] = false;
        }
    }
}

void fall()
{
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= 10; j++) {
            int ti = i;
            while (mat[i][j] != 0 && mat[ti + 1][j] == 0 && ti < n) {
                ti++;
            }
            swap(mat[ti][j], mat[i][j]);
        }
    }
}

int main()
{
    cin >> n >> k;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 0; j < 10; j++) {
            mat[i][j + 1] = str[j] - '0';
        }
    }
    bool update = true;
    while (update) {
        update = false;
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= 10; j++) {
                clear();
                vis[i][j] = true;
                if (check(i, j) >= k) {
                    clear();
                    del(i, j);
                    mat[i][j] = 0;
                    update = true;
                }
            }
        }
        fall();
    }
    show();
    return 0;
}