#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

int main()
{
    int n;
    cin >> n;
    while (n > 0) {
        string item;
        cin >> item;
        if (item == "+") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a + b);
        } else if (item == "-") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a - b);
        } else if (item == "*") {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a * b);
        } else {
            stk.push(stoi(item));
        }
        n--;
    }
    cout << stk.top() << endl;
    return 0;
}