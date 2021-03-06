#include <bits/stdc++.h>

using namespace std;

#define MAX_N 5001

// // TODO: List
struct Edge {
    int n1, n2, weight;
    inline bool operator<(Edge& rhs) const
    {
        return this->weight < rhs.weight;
    }
};
vector<Edge> random_engine(200001);

// // TODO: Union Find Set
int par[MAX_N];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findPar(int n)
{
    if (par[n] == n)
        return n;
    else {
        return par[n] = findPar(par[n]);
    }
}

void unite(int a, int b)
{
    a = findPar(a);
    b = findPar(b);
    if (a == b)
        return;
    par[b] = a;
}

bool isSamePar(int a, int b)
{
    return findPar(a) == findPar(b);
}

int main()
{
    // freopen("../../data/kruskal1.in", "r", stdin);
    //  // TODO: Input & Initialization
    // clock_t t = clock();
    int N,
        M;
    cin >> N >> M;
    init(N);
    for (int i = 1; i <= M; i++) {
        Edge te;
        cin >> te.n1 >> te.n2 >> te.weight;
        random_engine.push_back(te);
    }
    // //  TODO: tope sort
    sort(random_engine.begin(), random_engine.end());
    // // TODO: Kruskal algorithm
    int ans = 0;
    sort(random_engine.begin(), random_engine.end());
    for (vector<Edge>::iterator it = random_engine.begin(); it != random_engine.end(); it++) {
        if (isSamePar(it->n1, it->n2)) {
            continue;
        } else {
            ans += it->weight;
            unite(it->n1, it->n2);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (par[i] == i) {
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }
    // t = clock() - t;
    // cout << double(t) / CLOCKS_PER_SEC << endl;
    return 0;
}