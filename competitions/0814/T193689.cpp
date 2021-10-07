#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string a;
    cin >> n >> a;
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i - 1] == a[i + 1]) {
            cout << "No" << endl;
            exit(0);
        }
    }
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == a[i + 1]) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
    return 0;
}