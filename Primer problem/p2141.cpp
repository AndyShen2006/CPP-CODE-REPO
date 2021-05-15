#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int a[110]={0};
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int ans=0;
	bool flag[110];
	memset(flag, 0x00, sizeof(flag));
	sort(&a[0], &a[n-1]);
	for(int i=0; i<n; i++) {
		for(int j=i; j>=0; j--) {
			for(int k=i; k>=0; k--) {
				if(j==k)  continue;
				if(a[j]+a[k]==a[i]){
					ans++;
					flag[i]=true;
					break;
				}
			}
			if(flag[i]){
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

