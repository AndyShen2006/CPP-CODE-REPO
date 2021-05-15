#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,count;
	int r[200]={0};
	cin >> n;
	count=n;
	for(int i=0; i<n; i++) {
		cin >> r[i];
	}
	sort(r, &r[n]);
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			//if(i==j)  continue;
			if(r[i]==r[j])  r[i]=-1,count--;
		}
	}
	cout << count << endl;
	for(int i=0; i<n; i++) {
		if(r[i]>=0)  cout << r[i] << ' ';
	}
	return 0;
}

