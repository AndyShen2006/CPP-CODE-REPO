#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> primes;

void init(int n) {
	int tk=0;
	n+=10;  //more secuity
	while(n--) {
		v.push_back(tk);
	}
}

int main()
{
	int n,q;
	std::ios::sync_with_stdio(false);
	cin >> n >> q;
	init(n);
	for(int i=2; i<=n; i++) {
		if(v[i] == 0) {
			v[i] = i;
			primes.push_back(i);
		}
		for(auto it : primes) {
			if(it*i > n || it > v[i])  break;  //If out of range or this prime is greater than lowest prime,break
			printf("%d=%d*%d,",it*i,it,i);
			v[it*i] = it;
		}
		cout << endl;
	}
	/*
	int k;
	while(q--) {
		cin >> k;
		cout << primes[k-1]  << endl;
	}
	*/
	/*
	for(auto it : primes) {
		cout << it << endl;
	}
	cout << endl << endl;
	for(auto it : v) {
		cout << it << endl;
	}
	*/
	return 0;
} 
