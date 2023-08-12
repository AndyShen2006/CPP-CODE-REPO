#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
int main()
{
	ll t,n,ans;
	cin >> t;
	while(t--) {
		ans=0;
		cin >> n;
		for(ll i=1; n; n/=10,i*=9) {
			ans+=i*(n%10)-(n%10>=7?i:0);
		}
		cout << ans << endl;
	}
	return 0;
}

