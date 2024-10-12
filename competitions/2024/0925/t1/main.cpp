#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    int T;
    cin >> T;
    while(T--) {
        int x,k;
        cin >> x >> k;
        if(!k) {
            cout << 2 << endl;
        }else {
            cout << (x>>1)+1 << endl;
        }
    }
    return 0;
}
