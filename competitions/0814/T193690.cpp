#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int remain = n % 3;
    int div = n / 3;
    if (div == 0 && remain == 1) {
        cout << "-1" << endl;
        exit(0);
    }
    if (remain == 2) {
        cout << "2 3 ";
    }
    if (remain == 1 && div % 2 == 0) {
        cout << "5 15 10 1 ";
        for (int i = 2; i <= div; i++) {
            cout << "5 15 10 ";
        }
    } else {
        for (int i = 1; i <= div; i++) {
            cout << "5 15 10 ";
        }
        if (remain == 1 && div % 2 == 1) {
            cout << "1";
        }
    }

    cout << endl;
    return 0;
}