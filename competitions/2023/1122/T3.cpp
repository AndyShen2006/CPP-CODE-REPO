#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << (i & 1) + 1 << ' ';
    }
    cout << endl;
    return 0;
}