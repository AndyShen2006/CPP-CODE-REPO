#include <bits/stdc++.h>

using namespace std;

int fun(int t)
{
    if (t % 6 <= 3)
        return 4 * t;
    else
        return 12 - 4 * t;
}

int main()
{
    int ans = 0;
    for (int i = 0; i <= 12; i++) {
        if (12 - i == fun(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}