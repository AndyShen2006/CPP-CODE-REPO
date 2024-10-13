#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
constexpr int MAX_N = 50;
=======
constexpr int MAX_N = 60;
>>>>>>> fbc10f8 (Update on Oct.13th.2024)
struct Tune {
    int x {}, y {};
    char dir {};
    bool stat = true;
} tunes[MAX_N];
#define DEBUG 0

void modify(int p)
{
    switch (tunes[p].dir) {
    case 'N':
        tunes[p].y--;
        break;
    case 'S':
        tunes[p].y++;
        break;
    case 'W':
        tunes[p].x--;
        break;
    case 'E':
        tunes[p].x++;
        break;
    }
}

void check(int p, int q)
{
    if (tunes[p].stat && tunes[q].stat && tunes[p].x == tunes[q].x && tunes[p].y == tunes[q].y) { // Valid and same position
        tunes[p].stat = false;
        tunes[q].stat = false;
    }
}

int main()
{
    freopen("storyteller.in", "r", stdin);
    freopen("storyteller.out", "w", stdout);
    int n;
    string dirs;
    cin >> n >> dirs;
    for (int i = 1; i <= n; i++) {
        cin >> tunes[i].x >> tunes[i].y;
        tunes[i].x <<= 1;
        tunes[i].y = -(tunes[i].y << 1);
        tunes[i].dir = dirs[i - 1];
    }
#if DEBUG
    for (int i = 1; i <= n; i++) {
        cerr << tunes[i].x << ' ' << tunes[i].y << ' ' << tunes[i].dir << endl;
    }
#endif
    for (int t = -2000; t <= 2000; t++) {
        for (int i = 1; i <= n; i++) {
            modify(i);
        }
#if DEBUG
        for (int i = 1; i <= n; i++) {
            cerr << tunes[i].x << ' ' << tunes[i].y << endl;
        }
        cerr << endl;
#endif
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                check(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += tunes[i].stat;
    }
    cout << ans << endl;
    return 0;
}