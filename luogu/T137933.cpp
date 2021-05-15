#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	ull n,m;
	vector<ull> pos;
	vector<ull> values;
	cin >> n >> m;
	int temp;
	for(int i=1; i<=n; i++) {
		cin >> temp;
		pos.push_back(temp-1);
	}
	for(int i=1; i<=m; i++) {
		cin >> temp;
		values.push_back(temp);
	}
	ull cnt;
	for(auto it : values) {
		cnt=0;
		for(auto item : pos) {
			if(item % it == 0)  cnt++;
		}
		cout << cnt << endl;
	}
}
