#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000001;

struct Point {
    int x, y;
} ps[MAX_N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    sort(ps + 1, ps + n + 1, [](const Point& a, const Point& b) {
        return a.y == b.y ? a.x < b.x : a.y < b.y;
    });
    int curx = 0, cury = 0;
    for (int i = 1; i <= n; i++) {
        if (ps[i].x < curx || ps[i].y < cury || (ps[i].x == curx && ps[i].y == cury)) {
            cout << "ERR" << endl;
            break;
        }
        if (ps[i].x != curx && ps[i].y != cury) {
            cout << ps[i].x << ' ' << cury << endl;
        }
        curx = ps[i].x;
        cury = ps[i].y;
    }
}