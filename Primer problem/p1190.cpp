#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	int w[10010],s[101];
	//Input
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> w[i];
	//Main
	int t;
	for(int i=0; i<n; i++) {
		t=1;
		for(int j=1; j<m; j++) {
			if(s[t]>s[j])  t=j;
			s[t]+=w[i]
		}
	}
	return 0;
}

