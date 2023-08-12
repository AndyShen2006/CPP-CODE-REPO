#include<bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef unsigned long long int ull;
map<int, map<int, int> > dic;

int main()
{
	int N;
	ull n=1;
	cin >> N;
	auto start=clock();
	for(int i=1; i<=N; i++) {
		n*=i;
	}
	//make primes
	bool isPrimes[10001];
	vector<int> primes;
	memset(isPrimes, 0x01, sizeof(isPrimes));
	for(int i=2; i<=N; i++) {
		if(isPrimes[i]) {
			dic[i][i]=1;
		}
		for(int j=2*i; j<N; j+=i) {
			isPrimes[j]=false;
		}
	}
	for(int i=2; i<=N; i++) {
		if(isPrimes[i]){
			primes.push_back(i);
		} 
	}
	for(int i=4; i<=N; i++) {
		int k=i;
		while(isPrime[k]) {
			k[i]
		}
	}
	//Time
	auto end=clock();
	cout << "total time is" << (double)(end-start)/CLOCKS_PER_SEC << "s.";
	return 0;
}

