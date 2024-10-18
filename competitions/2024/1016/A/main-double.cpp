#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 ell;
constexpr int MAX_N = 1e6 + 10;
constexpr ll MOD = 1e9 + 7;

vector<double> ps[MAX_N];

void output(ell a)
{
    string s;
    while (a > 0) {
        s.push_back(char('0' + a % 10));
        a /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main()
{
    freopen("data/a2.in", "r", stdin);
    ll n, m;
    double a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++) {
        ps[i].push_back(-1);
        for (int j = 1; j <= m; j++) {
            int tmp;
            cin >> tmp;
            ps[i].push_back(tmp);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cerr << ps[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    double ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            double possB = (ps[i][j] / 100) * (ps[i + 1][j] / 100) * (ps[i][j + 1] / 100) * (ps[i + 1][j + 1] / 100);
            ans += possB * a;
            // cerr << possB << ' ';
            double possW = (1 - ps[i][j] / 100) * (1 - ps[i + 1][j] / 100) * (1 - ps[i][j + 1] / 100) * (1 - ps[i + 1][j + 1] / 100);
            ans += possW * b;
            // cerr << possW << endl;
        }
    }
    cerr << ans << endl;
    ell lans = ell(ans);
    output(lans % MOD);
    return 0;
}