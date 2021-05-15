#include<bits/stdc++.h>

using namespace std;

int main()
{
	//Input
	int id[5010]={0};
	int val[5010]={0};
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> id[i] >> val[i];
	}
	//Main
	//Sort
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(val[i]<val[j]){
				swap(val[i],val[j]);
				swap(id[i],id[j]);
			}
			if(val[i]==val[j]&&id[i]>id[j]) {
				swap(val[i],val[j]);
				swap(id[i],id[j]);
			}
		}
	}
	int minP=floor(m*1.5)-1;
	int minVal=val[minP];
	int ans[5010]={0};
	int count=0;
	//Output
	for(int i=0; i<n; i++) {
		if(val[i]>=minVal) {
			count++;
		}else{
			break;
		}
	} 
	cout << minVal << ' ' << count << endl;
	for(int i=0; i<n; i++) {
		if(val[i]>=minVal) {
			cout << id[i] << ' '  << val[i] << endl;
		}else{
			break;
		}
	}
	return 0;
}

