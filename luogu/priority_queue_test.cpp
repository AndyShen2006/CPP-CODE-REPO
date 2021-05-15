#include<bits/stdc++.h>

using namespace std;

struct Node{
	int a,b;
	bool operator ()(Node &a, Node &b) {
		return a.a >= b.a;
	}
};
/*
struct Symbol{
	
};
*/
/*
Node greater(Node n1, Node n2) {
	return n1.a >= n2.a ? n1 : n2;
}
*/
priority_queue<int> q1;
priority_queue<int, vector<int> ,greater<int> > q2;
priority_queue<Node, vector<Node> ,Node > q3;

int main()
{
	int input[100] = {0,2,5,4,3,1,9,8,7,0,6};
	Node tn;
	for(int i=1; i<=10; i++) {
		q1.push(input[i]);
		q2.push(input[i]);
		tn.a=input[i];
		tn.b=10-input[i];
		q3.push(tn);
	}
	while(!q1.empty()) {
		cout << q1.top() << ' ';
		q1.pop();
	}
	cout << endl << endl;
	while(!q2.empty()) {
		cout << q2.top() << ' ';
		q2.pop();
	}
	cout << endl << endl;

	while(!q3.empty()) {
		cout << '[' << q3.top().a << ',' << q3.top().b << "]\n";
		q3.pop();
	}

	return 0;
}
