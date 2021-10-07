#include <bits/stdc++.h>

using namespace std;

//map<char, map<int, string, greater<int>>> M;
map<char, vector<pair<int, string>>> M;

int main()
{
    //freopen("data/str2.in", "r", stdin);
    //freopen("data/str2.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int tempscore;
    string tempname;
    for (int i = 1; i <= n; i++) {
        cin >> tempname >> tempscore;
        M[tempname[tempname.size() - 1]].push_back(make_pair(tempscore, tempname));
    }
    for (auto it = M.begin(); it != M.end(); it++) {
        sort(it->second.begin(), it->second.end(), greater<pair<int, string>>());
    }
    /*
    for (auto it : M) {
        printf("%c:\n", it.first);
        for (auto ait : it.second) {
            printf("%s %d\n", ait.second.c_str(), ait.first);
        }
    }
    */
    char tc;
    int tn;
    for (int i = 1; i <= m; i++) {
        cin >> tc >> tn;
        if (tn > M[tc].size()) {
            cout << "Orz YYR tql\n";
        } else {
            cout << M[tc][tn - 1].second << endl;
        }
    }
    return 0;
}
/*
5 2
aaa 1
aa 2
a 3
ab 3
bb 4
b 2
a 4
*/
