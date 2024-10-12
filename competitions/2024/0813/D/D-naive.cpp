#include <bits/stdc++.h>

using namespace std;
constexpr int MAX_N = 5e5 + 10;
int p[MAX_N];

int main()
{
    int n, diff = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i) {
            diff++;
        }
    }
    while (diff) {
        int x = 0, posX = 0, y = INT_MAX, posY = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] != i && p[i] > x) {
                x = p[i];
                posX = i;
            }
        }
        for (int j = posX + 1; j <= n; j++) {
            if (p[j] < y) {
                y = p[j];
                posY = j;
            }
        }
        // cout << posX << ' ' << posY << endl;
        if (posX == p[posY]) {
            diff--;
        }
        if (posY == p[posX]) {
            diff--;
        }
        // cout << diff << endl;
        swap(p[posX], p[posY]);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}