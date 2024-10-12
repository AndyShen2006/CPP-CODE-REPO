#include <bits/stdc++.h>

using namespace std;

/*
n is odd, k is odd:
    n>=k: YES(let y=1,x=(n-k)/2)
    n<k: NO
n is odd, k is even: NO
n is even: YES(let y=0,x=n/2)
*/

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (((n & 1) && (k & 1) && n >= k) || n % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}