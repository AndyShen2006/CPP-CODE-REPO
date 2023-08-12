#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string a,b;
	cin >> n;
	cin >> a;
	for(int i=0; i<a.size(); i++) {
		if(a[i]+n>'z'){
			a[i]='a'+a[i]+n-'z'-1;
		}else{
			a[i]=a[i]+n;
		}
	}
	cout << a << endl;
	return 0;
}

