#include<bits/stdc++.h>

using namespace std;

int main()
{
	string data;
	getline(cin, data, 'E');
	//cout << data;
	int count=0,w11=0,l11=0,w21=0,l21=0;
	for(int i=0; i<data.size(); i++) {
		if(data[i]=='W')  w11++;
		if(data[i]=='L')  l11++;
		if(abs(w11-l11)>=2) {
			if(w11>=11||l11>=11){
				cout << w11 << ':' << l11 << endl;
				w11=0;
				l11=0;
			}
		}
	}
	//if(w11!=0||l11!=0)
		cout << w11 << ':' << l11 << endl;
	cout << endl;
	for(int i=0; i<data.size(); i++) {
		if(data[i]=='W')  w21++;
		if(data[i]=='L')  l21++;
		if(abs(w21-l21)>=2) {
			if(w21>=21||l21>=21){
				cout << w21 << ':' << l21 << endl;
				w21=0;
				l21=0;
			}
		}
	}
	//if(w11!=0||l11!=0)
		cout << w21 << ':' << l21 << endl;
	return 0;
}

