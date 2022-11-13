#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("data/gibbs5.in", "r", stdin);
    freopen("data/gibbs5.out", "w", stdout);
    int n, m, T;
    cin >> n >> m >> T;
    double tH, tS, sumH1 = 0, sumH2 = 0, sumS1 = 0, sumS2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tH >> tS;
        sumH1 += tH;
        sumS1 += tS;
    }
    for (int i = 1; i <= m; i++) {
        cin >> tH >> tS;
        sumH2 += tH;
        sumS2 += tS;
    }
    double G = (sumH2 - sumH1) - T * (sumS2 - sumS1);
    if (G == 0) {
        cout << "Equilibrium" << endl;
    } else if (G > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}