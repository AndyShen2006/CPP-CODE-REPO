#include<bits/stdc++.h>
#define MAX 1000

using namespace std;
int a[10001]={0};
int main()
{
	int n;
	cin >> n;
	auto start=clock();
	for(int i=2; i<=n; i++) {
		int k=i;
		for(int j=2; j<=i; j++) {
			while(k%j==0) {
				a[j]++;
				k/=j;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(a[i]!=0)
			cout << i << ' '<<a[i]<<endl;
	}
	//Time
	auto end=clock();
	//cout << "total time is" << (double)(end-start)/CLOCKS_PER_SEC << "s.";
	return 0;
}

