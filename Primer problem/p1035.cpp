#include<bits/stdc++.h>

using namespace std;

int main()
{
	double n=1,k,sum;
	cin >> k;
	while(true) {
		sum += 1/n;
		if(sum>k)  break;
		n++;
	}
	cout << n;
	return 0;
}

