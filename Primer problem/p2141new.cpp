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
	set<int> sum;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j)  continue;
			sum.insert(a[i]+a[j]);
		}
	}
	int ans=0;
	for(int i=0; i<n; i++) {
		if(sum.find(a[i])!=sum.end())  ans++;
	}
	cout << ans;
	return 0;
}

