#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> Q; // RP,Pos

int main()
{
    freopen("data/2a.in", "r", stdin);
    int T;
    cin >> T;
    string type;
    string name;
    int RP, pos, gcnt;
    for (int k = 1; k <= T; k++) {
        pos = gcnt = 0;
        Q.clear();
        while (true) {
            cin >> type;
            if (type == "START") {
                continue;
            } else if (type == "C") {
                pos++;
                cin >> name >> RP; // Name is useless, continue
                while (!Q.empty() && RP > Q.back().first) {
                    Q.pop_back();
                }
                Q.push_back(make_pair(RP, pos));
            } else if (type == "Q") {
                if (Q.empty()) {
                    cout << -1 << endl;
                } else {
                    cout << Q.front().first << endl;
                }

            } else if (type == "G") {
                gcnt++;
                if (gcnt >= Q.front().second) {
                    Q.pop_front();
                }
            } else if (type == "END") {
                break;
            }
        }
    }
    return 0;
}