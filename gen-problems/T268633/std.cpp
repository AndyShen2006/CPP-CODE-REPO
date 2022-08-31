#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    char c;
    int cur = 0;
    while ((c = getchar()) != EOF) {
        if (!(cur % 3)) {
            if (c != 'X') {
                ans++;
            }
        }
        cur++;
    }
    cout << ans << endl;
}