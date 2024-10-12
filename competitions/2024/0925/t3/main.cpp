#include <iostream>

using namespace std;

typedef long long ll;
constexpr int MAX_N = 2010;
constexpr int MOD = 998244353;
ll dp[MAX_N][MAX_N];
ll pre[MAX_N][MAX_N];

inline ll dur(int i,int l, int r)
{
    return pre[i][r]-pre[i][l-1];
}

int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            dp[i][j]=dp[i][j-1]+dur(i-1,1,j-2)+dp[i-1][j-1]+m+1;
        }
        for(int j=1; j<=k; j++) {
            pre[i][j]=pre[i][j-1]+dp[i][j];
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ans+=dur(i-1,1,k)*dp[j-i+1][k]*dur(n-j,1,k);
        }
    }
    cout << ans << endl;
    return 0;
}
