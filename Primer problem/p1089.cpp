#include<bits/stdc++.h>

using namespace std;

int main()
{
	int sum=0,old=0;
	int a[12]={0};
	for(int i=0; i<12; i++) {
		cin >> a[i];
	}
	for(int i=0; i<12; i++) {
		if(a[i]>300+old) {
			cout << -i-1
			;
			exit(0);
		}
		sum+=300+old-a[i]-(300+old-a[i])%100;
		old=300+old-a[i]-(300+old-a[i]-(300+old-a[i])%100);
		//cout << old << ' ' << sum << endl;
	}
	cout << sum*1.2+old;
	return 0;
}

