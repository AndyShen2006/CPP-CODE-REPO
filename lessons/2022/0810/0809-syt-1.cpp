#include <bits/stdc++.h>

using namespace std;

int a[10000];

struct Node {
    int l, r;
} tree[10000];
int n;

stack<int> st;
int root; //处理出根，用来遍历
void build()
{
    int last = 1; //处理最后一个出栈的元素
    st.push(1);
    for (int i = 2; i <= n; i++) {
        while (!st.empty() && a[i] < a[st.top()]) {
            last = st.top();
            st.pop();
        }
        if (st.empty()) {
            tree[i].l = last;
            root = i;
        } else {
            tree[st.top()].r = i;
        }
        st.push(i);
    }
}

void preorder(int x)
{
    cout << x << ' ';
    if (tree[x].l != 0) {
        preorder(tree[x].l);
    }
    if (tree[x].r != 0) {
        preorder(tree[x].r);
    }
}

void inorder(int x)
{
    if (tree[x].l != 0) {
        inorder(tree[x].l);
    }
    cout << x << ' ';
    if (tree[x].r != 0) {
        inorder(tree[x].r);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}