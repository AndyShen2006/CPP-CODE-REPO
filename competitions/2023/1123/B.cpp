#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, I;
    cin >> n >> I;
    if (I == n - 1) {
        cout << "I don't know" << endl;
    } else {
        cout << I << ' ' << 0 << ' ' << n - I << endl;
    }
    return 0;
}