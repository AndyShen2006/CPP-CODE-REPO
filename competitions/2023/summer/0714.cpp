#include <bits/stdc++.h>

using namespace std;

double edges[50];

inline double area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return p * (p - a) * (p - b) * (p - c);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> edges[i];
    }
    sort(edges + 1, edges + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (edges[i] + edges[j] > edges[k]) {
                    ans = max(ans, area(edges[i], edges[j], edges[k]));
                }
            }
        }
    }
    if (ans == 0) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(2) << sqrt(ans) << endl;
    }
    return 0;
}