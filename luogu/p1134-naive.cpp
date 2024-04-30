#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    __int128 ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    string sans;
    while (ans) {
        sans.push_back('0' + ans % 10);
        ans /= 10;
    }
    reverse(sans.begin(), sans.end());
    cout << sans << endl;
    return 0;
}