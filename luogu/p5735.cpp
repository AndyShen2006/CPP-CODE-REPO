#include <bits/stdc++.h>

using namespace std;

inline double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    double x1, x2, x3;
    double y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double d1 = dis(x1, y1, x2, y2);
    double d2 = dis(x1, y1, x3, y3);
    double d3 = dis(x2, y2, x3, y3);
    cout << fixed << setprecision(2) << d1 + d2 + d3 << endl;
    return 0;
}