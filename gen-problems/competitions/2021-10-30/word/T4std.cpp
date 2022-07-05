#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1000001;
string a[MAX_N]; //使用a[0]作为起始
int par[MAX_N];
typedef pair<string, int> P;
vector<P> M[30];
bool vis[MAX_N];

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
        M[a[i][0] - 'A'].emplace_back(a[i], i);
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
        char end = s.first[s.first.size() - 1];
        for (int i = 0; i < M[end - 'A'].size(); i++) {
            if (!vis[M[end - 'A'][i].second]) {
                q.push(M[end - 'A'][i]);
                vis[M[end - 'A'][i].second] = true;
                par[M[end - 'A'][i].second] = s.second;
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == s.first[s.first.size() - 1] && !vis[i]) {
                q.push(P(a[i], i));
                vis[i] = true;
                par[i] = s.second;
            }
        }
        */
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