#include <bits/stdc++.h>

using namespace std;

struct Node {
    int num;
    Node *next, *prev;
};

int main()
{
    int n, m;
    cin >> n >> m;
    Node* head = new Node();
    head->num = 1;
    Node *nowptr, *prevptr;
    prevptr = head;
    for (int i = 2; i <= n; i++) {
        nowptr = new Node();
        nowptr->num = i;
        prevptr->next = nowptr;
        nowptr->prev = prevptr;
        prevptr = nowptr;
    }
    nowptr->next = head;
    head->prev = nowptr;
    nowptr = head;
    int cnt = 0, size = n;
    Node* tempptr;
    while (size) {
        cnt++;
        if (cnt == m) {
            cnt = 0;
            nowptr->prev->next = nowptr->next;
            nowptr->next->prev = nowptr->prev;
            tempptr = nowptr->next;
            cout << nowptr->num;
            size--;
            delete nowptr;
            nowptr = tempptr;
        } else {
            nowptr = nowptr->next;
        }
    }
    cout << endl;
    return 0;
}