#include<bits/stdc++.h>

using namespace std;

int main()
{
	bool status[20000];
	memset(status, 0x01, 20000);
	int l,m;
	cin >> l >> m;
	int ts,tf;
	for(int i=0; i<m; i++) {
		cin >> ts >> tf;
		for(int i=ts; i<tf+1; i++) {
			status[i]=false;
		}
		//memset(&status[ts], 0x00, (size_t)(tf-ts+1));
	}
	int ans=0;
	for(int i=0; i<=l; i++) {
		if(status[i])  ans++;
		//cout << status[i];
	}
	cout << ans;
	return 0;
}

