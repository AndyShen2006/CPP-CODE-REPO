#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            cout << fixed << setprecision(5) << "Max: " << c << endl;
            cout << fixed << setprecision(5) << "Min: " << c << endl;
        } else {
            cout << fixed << setprecision(5) << "Max: " << "+inf" << endl;
            cout << fixed << setprecision(5) << "Min: " << "-inf" << endl;
        }
    } else {
        if (a > 0) {
            cout << fixed << setprecision(5) << "Max: " << "+inf" << endl;
            cout << fixed << setprecision(5) << "Min: " << (4 * a * c - b * b) / 4 * a << endl;
        } else {
            cout << fixed << setprecision(5) << "Max: " << (4 * a * c - b * b) / 4 * a << endl;
            cout << fixed << setprecision(5) << "Min: " << "-inf" << endl;
        }
    }
    return 0;
}