#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 2) {
        int a, b;
        cin >> a >> b;
        cout << a + b + min(a, b) << endl;
    } else {
        int a;
        cin >> a;
        cout << a << endl;
    }

    return 0;
}