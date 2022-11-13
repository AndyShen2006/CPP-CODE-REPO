// 2-3 Tree
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    char lData = '\0';
    char rData = '\0'; // This option will enabled when type is Three
    char tData = '\0'; // Temporary save node
    int type = Two;
    enum {
        Two,
        Three,
        Four // Temporary
    };
    Node() = default;
    explicit Node(char c)
    {
        lData = c;
    };
    Node(char c1, char c2)
    {
        lData = c1;
        rData = c2;
    }
    void order()
    {
        switch (type) {
        case Two:
            return;
            break;
        case Three:
            if (lData > rData) {
                swap(lData, rData);
            }
            break;
        case Four:
            if (lData > rData) {
                swap(lData, rData);
            }
            if (rData > tData) {
                swap(rData, tData);
            }
            if (lData > rData) {
                swap(lData, rData);
            }
            break;
        default:
            break;
        }
    }
    void split()
    {
        if (type == Four) {
            order();
            Node* tlNode = new Node;
            Node* trNode = new Node;
            tlNode->type = Two;
        } else {
            return;
        }
    }
};

Node root;

void put(char c, Node* cur)
{
}

bool get(char c, Node* cur)
{
}

void preorder(Node* cur)
{
    if (cur == nullptr) {
        return;
    }
    cout << cur->lData;
    preorder(cur->l);
    preorder(cur->r);
}

int main()
{
    freopen("data/bst1.in", "r", stdin);
    string str;
    cin >> str;
    root.lData = str.front();
    for (int i = 1; i < str.size(); i++) {
        put(str[i], &root);
    }
    preorder(&root);
    cout << endl;
    int n;
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        cout << get(c, &root) << endl;
    }
    return 0;
}