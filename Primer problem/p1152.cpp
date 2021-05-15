#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[2000]={0};
	int c[2000]={0};
	int n;
	cin >> n;
	bool status=true;
	//Input
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int old;
	for(int i=1; i<n; i++) {
		c[i]=abs(a[i]-a[i+1]);
	}
	sort(c+1, c+n);
	for(int i=1; i<n; i++){
		if(c[i]!=i)  cout << "Not jolly",exit(0);
	}
	cout << "Jolly";
	return 0;
}

