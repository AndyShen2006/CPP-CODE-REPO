#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string n;
    for (int i = 1; i <= T; i++) {
        cin >> n;
        bool flag = false;
        int sum = 0;
        for (auto it : n) {
            sum += it - '0';
            if (it == '0') {
                flag = true;
            }
        }
        if (flag) {
            cout << sum + 9 << endl;
        } else {
            cout << sum + 8 << endl;
        }
    }
    return 0;
}