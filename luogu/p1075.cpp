#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
bool isPrimes[45000];
vector<ull> primes;
int main()
{
	ull n;
	cin >> n;
	memset(isPrimes, 0x01, sizeof(isPrimes));
	for(int i=2; i<sqrt(n); i++) {
		for(int j=2*i; j<sqrt(n); j+=i) {
			isPrimes[j]=false;
		}
	}
	for(int i=2; i<sqrt(n); i++) {
		if(isPrimes[i])  primes.push_back(i);  
	}
	ull a;
	for(int i=0; i<sqrt(n); i++) {
		if(n%primes[i]==0){
			a=primes[i];
			break;	
		}
	}
	if(a>n/a)  cout << a;
	else  cout << n/a;
	return 0;
}

