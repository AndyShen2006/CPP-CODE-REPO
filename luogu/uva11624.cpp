#include <bits/stdc++.h>

using namespace std;

char d[1010][1010] = { { 0 } };
int now[1010][1010] = { { 0 } };
int t, r, c;

struct fun {
    int row, column, tnow;
    static fun make_fun(int tr, int tc, int tn)
    {
        fun tfun;
        tfun.row = tr, tfun.column = tc, tfun.tnow = tn;
        return tfun;
    }
};

namespace getdata {
queue<fun> q;
inline void push(fun fnow)
{
    if (fnow.row <= r && fnow.column <= c) {
        now[fnow.row][fnow.column] = min(now[fnow.row][fnow.column], fnow.tnow + 1);
        q.push(fun::make_fun(fnow.row, fnow.column, fnow.tnow + 1));
    }
}
void getnow()
{
    //Get fire position
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (d[i][j] == 'F') {
                q.push(fun::make_fun(i, j, 0));
                now[i][j] = 0;
            } else if (d[i][j] == '#') {
                now[i][j] = -1;
            }
        }
    }
    fun fnow;
    while (!q.empty()) {
        fnow = q.front();
        push(fun::make_fun(fnow.row + 1, fnow.column, fnow.tnow + 1));
        push(fun::make_fun(fnow.row - 1, fnow.column, fnow.tnow + 1));
        push(fun::make_fun(fnow.row, fnow.column + 1, fnow.tnow + 1));
        push(fun::make_fun(fnow.row, fnow.column - 1, fnow.tnow + 1));
    }
}
fun returnJoePos()
{
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (d[i][j] == 'J') {
                return fun::make_fun(i, j, 0);
            }
        }
    }
    //Error
    return fun::make_fun(-1, -1, -1);
}
}
namespace solution {
queue<fun> q;
inline int PosStatus(fun fnow)
{
    //0 ->has already solution, 1->can't walk(already in fire), 2->can walk
    if (fnow.row == r || fnow.column == c) {
        return 0;
    } else if (now[fnow.row][fnow.column] < fnow.tnow) {
        return 1;
    } else {
        return 2;
    }
}
void solve()
{
    getdata::getnow();
    q.push(getdata::returnJoePos());
    fun fnow;
    while (!q.empty()) {
        fnow = q.front();
        if (PosStatus(fnow) == 0) {
            cout << fnow.tnow << endl;
            return;
        }
        if (PosStatus(fnow) == 1) {
            continue;
        }
        q.push(fun::make_fun(fnow.row + 1, fnow.column, fnow.tnow + 1));
        q.push(fun::make_fun(fnow.row - 1, fnow.column, fnow.tnow + 1));
        q.push(fun::make_fun(fnow.row, fnow.column + 1, fnow.tnow + 1));
        q.push(fun::make_fun(fnow.row, fnow.column - 1, fnow.tnow + 1));
    }
    cout << "IMPOSSIBLE" << endl;
    return;
}
}

int main()
{
    freopen("data/uva11624a.in", "r", stdin);
    cin >> t >> r >> c;
    for (int i = 1; i <= t; i++) {
        //Input
        for (int j = 1; j <= r; j++) {
            for (int k = 1; k <= c; k++) {
                cin >> d[j][k];
            }
        }
        solution::solve();
    }
    return 0;
}