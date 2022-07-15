#include <bits/stdc++.h>

using namespace std;

constexpr int type0 = 0;
constexpr int type1 = 1; /* ->/ */
constexpr int type2 = 2; /* ->\ */
constexpr int typeS = 3;
constexpr int typeBS = 4;

struct task {
    int l, n;
    bool operator>(const task& rhs) const
    {
        if (l == rhs.l) {
            return n > rhs.n;
        } else {
            return l > rhs.l;
        }
    }
};

inline int bipow(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++) {
        ans *= 2;
    }
    return ans;
}

int nG[4096][4096];
int G[4096][4096];
int m, n;
int sumLevel;
task tasks[20];

void show()
{
    for (int i = 1; i <= sumLevel; i++) {
        for (int j = 1; j <= 2 * sumLevel - 1; j++) {
            if (G[i][j] == type1 || G[i][j] == type2) {
                cout << 'o';
            } else if (G[i][j] == typeS) {
                cout << '/';
            } else if (G[i][j] == typeBS) {
                cout << '\\';
            } else if (G[i][j] == type0) {
                cout << ' ';
            }
        }
        if (i != sumLevel) {
            cout << endl;
        }
    }
}

void dfs(int r, int c)
{
    if (r > sumLevel || c <= 0 || c > 2 * sumLevel - 1) {
        return;
    }
    if (G[r][c] == type1 || G[r][c] == type2) {
        dfs(r + 1, c - 1);
        dfs(r + 1, c + 1);
    } else if (G[r][c] == typeS) {
        dfs(r + 1, c - 1);
    } else if (G[r][c] == typeBS) {
        dfs(r + 1, c + 1);
    } else {
        return;
    }
    G[r][c] = type0;
}

int main()
{
    // freopen("data/p1185c.in", "r", stdin);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tasks[i].l >> tasks[i].n;
    }
    sumLevel = 3 * bipow(m - 2);
    // For line 1
    int pos = 1;
    for (int i = 1; i <= bipow(m - 1); i++) {
        if (i % 2 == 1) {
            nG[1][pos] = type1;
            pos += 4;
        } else {
            nG[1][pos] = type2;
            pos += 2;
        }
    }
    // For other lines
    int level, step;
    for (int i = 2; i <= m; i++) {
        level = 3 * bipow(i - 2);
        step = 2 * level;
        pos = level;
        for (int j = 1; j <= bipow(m - i); j++) {
            if (j % 2 == 1) {
                nG[level][pos] = type1;
                pos += step;
            } else {
                nG[level][pos] = type2;
                pos += step;
            }
        }
    }
    // Reverse
    for (int i = 1; i <= sumLevel; i++) {
        for (int j = 1; j <= 2 * sumLevel - 1; j++) {
            G[i][j] = nG[sumLevel - i + 1][j];
        }
    }
    // Generate edge
    int row, column;
    for (int i = sumLevel; i > 1; i--) {
        for (int j = 1; j <= 2 * sumLevel - 1; j++) {
            if (G[i][j] == type1) {
                row = i - 1;
                column = j + 1;
                while (true) {
                    if (G[row][column] == type0) {
                        G[row][column] = typeS;
                        row--;
                        column++;
                    } else {
                        break;
                    }
                }
            } else if (G[i][j] == type2) {
                row = i - 1;
                column = j - 1;
                while (true) {
                    if (G[row][column] == type0) {
                        G[row][column] = typeBS;
                        row--;
                        column--;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    // Delete Node
    sort(tasks + 1, tasks + n + 1, greater<task>());
    int num, cnt;
    for (int i = 1; i <= n; i++) {
        level = tasks[i].l;
        num = tasks[i].n;
        if (level < m) {
            level = 3 * bipow(m - 2) + 1 - 3 * bipow(m - level - 1);
        } else {
            level = 3 * bipow(m - 2);
        }
        cnt = 0;
        for (int j = 1; j <= 2 * sumLevel - 1; j++) {
            if (G[level][j] == type1 || G[level][j] == type2) {
                cnt++;
            }
            if (cnt == num) {
                if (G[level][j] == type1) {
                    row = level - 1;
                    column = j + 1;
                    while (true) {
                        if (G[row][column] == typeS) {
                            G[row][column] = type0;
                            row--;
                            column++;
                        } else {
                            break;
                        }
                    }
                } else if (G[level][j] == type2) {
                    row = level - 1;
                    column = j - 1;
                    while (true) {
                        if (G[row][column] == typeBS) {
                            G[row][column] = type0;
                            row--;
                            column--;
                        } else {
                            break;
                        }
                    }
                }
                dfs(level, j);
                break;
            }
        }
    }
    show();
    return 0;
}