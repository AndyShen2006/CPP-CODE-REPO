#include <bits/stdc++.h>

using namespace std;

map<int, int> rf;
int pc[1000010];
int p(int x)
{
    int ans = 0;
    if (~pc[x]) {
        ans = pc[x];
    } else if (rf.find(x) != rf.end()) {
        ans = 2 * rf[x] + 1;
    } else if (x & 1) {
        ans = 2 * p(x >> 1) + 1;
    } else {
        ans = (p(x - 1) + p(x + 1)) >> 1;
    }
    pc[x] = ans;
    rf[ans] = x;
    return ans;
}

int main()
{
    memset(pc, -1, sizeof(pc));
    pc[1] = 2;
    rf[2] = 1;
    for (int i = 1; i <= 1000000; i++) {
        p(i);
    }
    for (int i = 1; i <= 50; i++) {
        cout << i << ' ' << p(i) << endl;
    }
    return 0;
}