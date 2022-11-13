#include <bits/stdc++.h>

using namespace std;

string a[100010]; //使用a[0]作为起始
int par[100010];
bool vis[100010];
typedef pair<string, int> P;

vector<string> ans;
int cnt = 0;
void dfs(int pos)
{
    ans.push_back(a[pos]);
    if (pos == 0) {
        return;
    }
    cnt++;
    dfs(par[pos]);
}

int main()
{
    //freopen("data/T4-9.in", "r", stdin);
    //freopen("data/T4-3.out", "w", stdout);
    //double s = clock();
    string end;
    cin >> a[0] >> end;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    queue<P> q;
    q.push(P(a[0], 0)); //第一项记录当前字符串，第二项记录当前字符串在a当中编号
    int posend = 0;
    vis[0] = true;
    bool sign = false;
    while (!q.empty()) {
        P s = q.front();
        q.pop();
        if (s.first == end) {
            posend = s.second;
            sign = true;
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == s.first[s.first.size() - 1] && !vis[i]) {
                q.push(P(a[i], i));
                vis[i] = true;
                par[i] = s.second;
            }
        }
    }
    if (sign) {
        dfs(posend);
        //reverse(ans.begin(), ans.end());
        cout << cnt << endl;
        for (int i = ans.size() - 1; i > 0; i--) {
            cout << ans[i] << " -> ";
        }
        cout << end << endl;
    } else {
        cout << -1 << endl;
    }
    //cout << double((clock() - s) / CLOCKS_PER_SEC);
    return 0;
}