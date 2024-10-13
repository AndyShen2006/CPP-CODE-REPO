#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 60;
char sq[MAX_N][MAX_N];
vector<pair<int, int>> pts;
#define DEBUG 0

int main()
{
#if DEBUG
    freopen("data/crosswords1.in", "r", stdin);
#else
    freopen("crosswords.in", "r", stdin);
    freopen("crosswords.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (sq[i] + 1);
    }
#if DEBUG
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cerr << sq[i][j] << ' ';
        }
        cerr << endl;
    }
#endif
    for (int i = 1; i <= n; i++) { // Enum (i,j)
        for (int j = 1; j <= m; j++) {
            int t = 0;
            if (i - 1 <= 0 || sq[i - 1][j] == '#') { // Check Column
                while (sq[i + t][j] != '#' && i + t <= n) {
                    t++;
                }
                if (t >= 3) {
                    sq[i][j] = '!';
                }
            }
            t = 0;
            if (j - 1 <= 0 || sq[i][j - 1] == '#') { // Check Row
                while (sq[i][j + t] != '#' && j + t <= m) {
                    t++;
                }
                if (t >= 3) {
                    sq[i][j] = '!';
                }
            }
        }
    }
#if DEBUG
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cerr << sq[i][j] << ' ';
        }
        cerr << endl;
    }
#endif
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sq[i][j] == '!') {
                pts.emplace_back(i, j);
            }
        }
    }
    cout << pts.size() << endl;
    for (auto it : pts) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}