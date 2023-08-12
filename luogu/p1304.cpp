#include<bits/stdc++.h>

using namespace std;

bool judge[100000];
int start=2;
bool isPrime(int n)
{
	return judge[n];
}
int main()
{
	memset(judge, 0x01, sizeof(judge));
	int n;
	for(int i=2; i<=n; i++) {
		for(int j=2*i; j<=n; j+=i) {
			judge[j]=false;
		}
	}
	cin >> n;
	for(int i=4; i<=n; i+=2) {
		for(int j=2;j<i; j++){
			if(isPrime(j) && isPrime(i-j)){
				cout << i << '=' << j << '+' << i-j << endl;
				break;
			}
		}
	}
	return 0;
}

