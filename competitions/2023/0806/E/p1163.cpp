#include <bits/stdc++.h>

using namespace std;

double w0, w, m;

bool check(double p)
{
    return (pow(1.0 / (1.0 + p), m) >= 1 - w0 / w * p);
}

int main()
{
    cin >> w0 >> w >> m;
    double l = 0, r = 10;
    while (r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}