#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
ll m,n;
ll ans[10]={0};

int main()
{
	cin >> m >> n;
	int k;
	for(int i=m; i<=n; i++) {
		k=i;	 
		while (k) {
			ans[k%10]++;
			k /= 10;
		}
	}
	for(int j=0;j<10; j++) {
		cout << ans[j] << ' ';
	}
	return 0;
}

