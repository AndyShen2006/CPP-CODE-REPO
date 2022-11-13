#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
	string text,pattern;
	cin >> text >> pattern;
	int i=0,j,ans=0;
	for(; i<text.size()-pattern.size(); i++) {
		for(j=0; j<pattern.size(); j++) {	
			if(text[i+j] != pattern[j]){
				//printf("text[%d]:%s != pattern[%d]:%s\n",i,&text[i],j,&pattern[j]);
				//cout << "text" << i << ":" << text[i] <<"!=" << "pattern" << ":" << pattern[j] << j << endl;
				break;
			}
		}
		if(j==pattern.size()){
			ans++;
			cout << i << endl;
		}
	}
	cout << ans;
	*/
    //freopen("KMP3.in", "r", stdin);
    //freopen("KMP.out","rw",stdout);
    string text, pattern;
    int lps[1000] = {0};
    cin >> text >> pattern;
    //cin >> pattern;
    int n = text.size(), m = pattern.size();
    int s = 0, j = 0, ans = 0; //s->text,j->pattern
    //KMP Prepare
    int k = 0, q = 1; //q->suffix
    while (q < m) {
        if (pattern[q] == pattern[k]) {
            k++;
            lps[q] = k;
            q++;
        } else {
            if (k == 0) {
                lps[q] = 0;
                q++;
            } else {
                k = lps[k - 1];
            }
        }
    }
    //Main
    for (int i = 0; i < m; i++) {
        cout << i << ' ' << lps[i] << endl;
    }
    while (s < n - m) {
        if (text[s] == pattern[j]) {
            s++;
            j++;
        } else {
            if (j == 0) {
                s++;
            } else {
                j = lps[j - 1];
            }
        }
        if (j == m - 1) {
            s++;
            j = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
