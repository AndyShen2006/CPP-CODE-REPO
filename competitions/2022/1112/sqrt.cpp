#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % (i * i) == 0) {
            cout << i << ' ' << n / (i * i) << endl;
            exit(0);
        }
    }
    return 0;
}