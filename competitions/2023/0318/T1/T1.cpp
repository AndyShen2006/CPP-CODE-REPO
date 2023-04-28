#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    long long x, ans;
    for (int i = 1; i <= t; i++) {
        cin >> x;
        ans = 1;
        if (x % 3 == 2) {
            cout << 0 << endl;
            continue;
        }
        if (x % 3 == 1) {
            x /= 3;
        }
        while (x > 0) {
            if (x % 3 == 1) {
                ans <<= 1;
            }
            x /= 3;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3
12 // 110  10010
2  // 002
13  // 111
进制转换为3进制下1的个数记作n,2^n即为答案。
*/