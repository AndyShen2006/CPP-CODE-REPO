#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,x,ans;
	cin >> n >> x;
	for(int i=1; i<=n; i++) {
		int k=i;
		while(k) {
			if(k%10==x)  ans++;
			k/=10;
		}
	}
	cout << ans;
	return 0;
}

