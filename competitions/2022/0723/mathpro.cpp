#include <bits/stdc++.h>

using namespace std;

struct Node {
    char ch;
    int pos;
    inline bool operator<(const Node& rhs) const
    {
        return this->ch == rhs.ch ? this->pos > rhs.pos : this->ch < rhs.ch;
    }
};

priority_queue<Node, vector<Node>, less<Node>> pq;

int main()
{
    int n, m;
    fscanf(stdin, "%d %d", &n, &m); // NOLINT
    char c;
    int npos = 0;
    getchar();
    getchar();
    c = getchar();
    m = n - m;
    register Node a, tmp;
    for (register int i = 1; i <= n; i++) {
        tmp.ch = c;
        tmp.pos = i;
        pq.emplace(tmp);
        if (i == n - m + 1) {
            do {
                a = pq.top();
                pq.pop();
            } while (a.pos < npos);
            putchar(a.ch);
            npos = a.pos;
            m--;
        }
        c = getchar(); // NOLINT
    }
    fprintf(stdin, "\n");
    return 0;
}