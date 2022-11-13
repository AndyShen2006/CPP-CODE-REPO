#include <bits/stdc++.h>

using namespace std;

int cnt[10 + 3 + 2];

inline void judge(char c)
{
    switch (c) {
    case 'A':
        cnt[0]++;
        break;
    case '2':
        cnt[1]++;
        break;
    case '3':
        cnt[2]++;
        break;
    case '4':
        cnt[3]++;
        break;
    case '5':
        cnt[4]++;
        break;
    case '6':
        cnt[5]++;
        break;
    case '7':
        cnt[6]++;
        break;
    case '8':
        cnt[7]++;
        break;
    case '9':
        cnt[8]++;
        break;
    case 'T':
        cnt[9]++;
        break;
    case 'J':
        cnt[10]++;
        break;
    case 'Q':
        cnt[11]++;
        break;
    case 'K':
        cnt[12]++;
        break;
    case 'X':
        cnt[13]++;
        break;
    case 'D':
        cnt[14]++;
        break;
    default:
        break;
    }
}

int main()
{
    // freopen("data/poker1.in", "r", stdin);
    int t;
    cin >> t;
    string card;
    bool sign;
    for (int i = 1; i <= t; i++) {
        cin >> card;
        memset(cnt, 0, sizeof(cnt));
        for (auto it : card) {
            judge(it);
        }
        sign = false;
        if (cnt[13] >= 1 && cnt[14] >= 1) {
            sign = true;
        }
        for (int i : cnt) {
            if (i >= 4) {
                sign = true;
                break;
            }
        }
        if (sign) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}