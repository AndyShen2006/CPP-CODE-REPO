#include <bits/stdc++.h>

using namespace std;

inline long long lowbit(long long x)
{
    return x & (-x);
}

inline int popcount(long long x)
{
    long long cnt = 0;
    while (x > 0) {
        cnt += (x & 1);
        x >>= 1;
    }
    return (int)cnt;
}

int main()
{
    int T;
    long long a;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a;
        int pc = popcount(a);
        if (pc >= 3) {
            cout << "No,Commander" << endl;
        } else if (pc == 2) {
            cout << a + lowbit(a) << endl;
        } else {
            cout << a + 1 << endl;
        }
    }
    return 0;
}