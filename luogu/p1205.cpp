#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 10;
string mat[MAX_N], emat[MAX_N];
char tmat[MAX_N][MAX_N], tmp[MAX_N][MAX_N];
int n;

void type1()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = mat[n - j - 1][i];
        }
    }
}

void type2()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = mat[n - i - 1][n - j - 1];
        }
    }
}

void type3()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = mat[j][n - i - 1];
        }
    }
}

void type4()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = mat[i][n - j - 1];
        }
    }
}

void type51()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = mat[i][n - j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = tmp[n - j - 1][i];
        }
    }
}

void type52()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = mat[i][n - j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = tmp[n - i - 1][n - j - 1];
        }
    }
}
void type53()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = mat[i][n - j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = tmp[j][n - i - 1];
        }
    }
}

void type6()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmat[i][j] = mat[i][j];
        }
    }
}

bool cmp()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tmat[i][j] != emat[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> emat[i];
    }
    type1();
    if (cmp()) {
        cout << 1 << endl;

        exit(0);
    }
    type2();
    if (cmp()) {
        cout << 2 << endl;
        exit(0);
    }
    type3();
    if (cmp()) {
        cout << 3 << endl;
        exit(0);
    }
    type4();
    if (cmp()) {
        cout << 4 << endl;
        exit(0);
    }
    type51();
    if (cmp()) {
        cout << 5 << endl;
        exit(0);
    }
    type52();
    if (cmp()) {
        cout << 5 << endl;
        exit(0);
    }
    type53();
    if (cmp()) {
        cout << 5 << endl;
        exit(0);
    }
    type6();
    if (cmp()) {
        cout << 6 << endl;
        exit(0);
    }
    cout << 7 << endl;
    return 0;
}