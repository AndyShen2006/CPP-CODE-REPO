#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

unordered_set<string> S;

int main()
{
    int n;
    cin >> n;
    string tempStr;
    for(int i=0; i<n; i++) {
        cin >> tempStr;
        if(S.find(tempStr)==S.end())  S.insert(tempStr);
    }
    cout << S.size() << endl;
    return 0;
}