#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	int s[101];
	deque<int> w;
	//Input
	cin >> n >> m;
	int t;
	for(int i=0; i<n; i++){
		cin >> t;
		w.push_back(t);
	}
	//Main
	int buffer[110]={0};
	int ans=0,pos=0;
	buffer[0]=w.front();  //make line
	w.pop_front();	
	/*while(true) {
		if(pos==m-1)  break;
		for(int i=pos; i<m; i++) { //into buffer
			if(buffer[i]==0) {
				if(!w.empty()) {
					buffer[i]=w.front();
					w.pop_front();
				}else if(w.empty()) {
					sort(&buffer[pos], &buffer[m-1]);
					pos++;   //lose first position
				}
			}
		}*/
		for(int i=pos; i<m; i++) { //into buffer
			if(buffer[i]==0) {
					buffer[i]=w.front();
					w.pop_front();
			}
		}
		for(int i=pos; i<m; i++)  cout << buffer[i] << ' ';
		cout << endl << endl;
		sort(&buffer[0], &buffer[3], std::less<int>());  //sort
		//for(auto item : w)  cout << item << ' ';
		//cout << endl;
		for(int i=pos; i<m; i++)  cout << buffer[i] << ' ';
		cout << endl << endl;
		/*for(int i=pos; i<m; i++) {
			buffer[i]-=buffer[pos];
			ans+=buffer[pos];
		}
	}*/
	cout << ans;
	return 0;
}

