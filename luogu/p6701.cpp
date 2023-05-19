#include <bits/stdc++.h>

using namespace std;

vector<string> rules; // <<pattern1,pattern2>,source>
bool dp[2010][2010][30]; // l,r,character
int g[3000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    rules.reserve(3000);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        rules.push_back(tmp);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        // Input
        char genotype[3000];
        cin >> (genotype + 1);
        // Initialization
        memset(dp, 0, sizeof dp);
        int slen = static_cast<int>(strlen(genotype + 1));
        for (int i = 1; i <= slen; i++) {
            dp[i][i][genotype[i] - 'A' + 1] = true;
        }
        for (int len = 2; len <= slen; len++) {
            for (int L = 1; L + len - 1 <= slen; L++) {
                int R = L + len - 1;
                for (int k = L; k < R; k++) {
                    for (auto x : rules) {
                        dp[L][R][x[0] - 'A' + 1] |= dp[L][k][x[1] - 'A' + 1] & dp[k + 1][R][x[2] - 'A' + 1];
                    }
                }
            }
        }
        dp[0][0]['S' - 'A' + 1] = true;
        g[0] = 0;
        for (int i = 1; i <= slen; i++) {
            g[i] = 0x3f3f3f3f;
            for (int j = 0; j <= i; j++) {
                if (dp[j + 1][i]['S' - 'A' + 1]) {
                    g[i] = min(g[i], g[j] + 1);
                }
            }
        }
        if (g[slen] == 0x3f3f3f3f) {
            cout << "NIE" << endl;
        } else {
            cout << g[slen] << endl;
        }
    }
    return 0;
}