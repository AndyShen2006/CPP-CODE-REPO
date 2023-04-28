#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        ll n, op, data;
        __int128 ans = 0;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> op;
            switch (op) {
            case 1:
                ans <<= 1;
                break;
            case 2:
                cin >> data;
                ans += data;
                break;
            default:
                break;
            }
        }
        if (ans == 0) {
            cout << 0 << endl;
        } else {
            string ansstr;
            while (ans > 0) {
                ansstr.push_back(static_cast<char>(ans % 2) + '0');
                ans /= 2;
            }
            reverse(ansstr.begin(), ansstr.end());
            cout << ansstr << endl;
        }
    }
    return 0;
}
/*
设在当前之后进行了i次1类操作

当前2类操作值为d。

ans+=d*pow(2,i);


*/