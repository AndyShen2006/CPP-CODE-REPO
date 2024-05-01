#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& rhs) const
    {
        return l < rhs.l;
    }
};
set<Interval> ct;

int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    return 0;
}