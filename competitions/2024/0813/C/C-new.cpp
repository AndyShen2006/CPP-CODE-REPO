#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 200010;
int sum;
string s;
string ss[6];
#define DEBUG 0

int main()
{
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> s;
    int i;
    for (i = 0; i <= n; i += 3) {
        ss[0] += "abc";
        ss[1] += "acb";
        ss[2] += "bac";
        ss[3] += "bca";
        ss[4] += "cab";
        ss[5] += "cba";
    }
    if (n - i == 1) {
        ss[0] += "a";
        ss[1] += "a";
        ss[2] += "b";
        ss[3] += "b";
        ss[4] += "c";
        ss[5] += "c";
    }
    if (n - i == 2) {
        ss[0] += "ab";
        ss[1] += "ac";
        ss[2] += "ba";
        ss[3] += "bc";
        ss[4] += "ca";
        ss[5] += "cb";
    }
    return 0;
}