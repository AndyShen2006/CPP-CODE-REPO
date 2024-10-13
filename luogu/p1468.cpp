#include <bits/stdc++.h>

using namespace std;

/*
There's several types of methods:
0
1 2 3 4
12=3 13=2 14 23=1 24 34
After reducing, we can find effective methods as follows:
0(0)
1(1) 2(2) 3(3) 4(4)
14(5) 24(6) 34(7)
*/
constexpr int MAX_N = 110;
int n, c;
int ans[MAX_N]; // 0->undef, 1->off, 2->on
int src[MAX_N][8];
bool check(int num)
{
    for (int i = 1; i <= n; i++) {
        if (src[num][i] == 0) {
            continue;
        }
        if (src[num][i] - 1 != ans[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> c;
    while (true) {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            break;
        }
        ans[tmp] = 2;
    }
    while (true) {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            break;
        }
        ans[tmp] = 1;
    }
    for (int i = 1; i <= n; i++) {
        src[1][i] = !src[1][i];
        src[5][i] = !src[5][i];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            src[2][i] = !src[2][i];
            src[6][i] = !src[6][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            src[3][i] = !src[3][i];
            src[7][i] = !src[7][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 1) {
            src[4][i] = !src[4][i];
            src[5][i] = !src[5][i];
            src[6][i] = !src[6][i];
            src[7][i] = !src[7][i];
        }
    }
    if (c) {
    }
    return 0;
}