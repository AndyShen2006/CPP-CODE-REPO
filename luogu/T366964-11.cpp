#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int main()
{
    for (int i = 1; i <= 5; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 1; k < i; k++) {
                for (int l = -4; l >= 4;) {
                }
            }
        }
    }
    return 0;
}