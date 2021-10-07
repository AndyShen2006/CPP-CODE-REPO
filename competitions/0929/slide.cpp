#include <bits/stdc++.h>

using namespace std;

int a[100001];

struct Node {
    int data;
    int place;
};

deque<Node> maxQ;
deque<Node> minQ;
int windowsize;
void add(Node n)
{
    // Kill dead value
    while (!maxQ.empty() && maxQ.front().place < 0) {
        maxQ.pop_front();
    }
    while (!minQ.empty() && minQ.front().place < 0) {
        minQ.pop_front();
    }
    // Update all queue
    //cout << "Debug1\n";
    if (!maxQ.empty())
        for (deque<Node>::iterator it = maxQ.begin(); it != maxQ.end(); it++) {
            it->place--;
        }
    if (!minQ.empty())
        for (deque<Node>::iterator it = minQ.begin(); it != minQ.end(); it++) {
            it->place--;
        }
    // Add and Update
    //cout << "Debug2\n";
    while (!maxQ.empty() && n.data > maxQ.front().data) {
        maxQ.pop_front();
    }
    maxQ.push_back(n);
    while (!minQ.empty() && n.data < minQ.front().data) {
        minQ.pop_front();
    }
    minQ.push_back(n);
}

int main()
{
    freopen("slide.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int ans;
    for (int i = 0; i <= n; i++) {
        ans = 0;
        for (int j = 0; j <= n - i; j++) {
            add(Node { a[j], i });
            cout << "Debug3\n";
            for (auto it : minQ) {
                printf("%d %d\n", it.data, it.place);
            }
            for (auto it : maxQ) {
                printf("%d %d\n", it.data, it.place);
            }
            ans += maxQ.front().data * minQ.front().data;
        }
        printf("%d ", ans);
    }
    return 0;
}