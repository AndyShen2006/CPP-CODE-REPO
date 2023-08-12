#include <bits/stdc++.h>
#include <ext_random.hpp>

using namespace std;
using namespace cdg;

vector<int> lis, ans;

int main()
{
    int n = randint(400, 500), q = randint(300000, 500000);
    cout << n << ' ' << q << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = randint(1, 1e9);
            lis.push_back(tmp);
            cout << tmp << ' ';
        }
        cout << endl;
    }
    sort(lis.begin(), lis.end(), greater<int>());
    int start = randint(1, n / 3);
    int length = randint(q / 2, q);
    int end = start + length - 1;
    for (int i = start; i <= end; i++) {
        ans.push_back(lis[i]);
    }
    int r = q - length;
    for (int i = 1; i <= r; i++) {
        ans.push_back(randint(1, 1e9));
    }
    shuffle(ans.begin(), ans.end(), rand_eng);
    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}