#include <bits/stdc++.h>

using namespace std;

constexpr int TOKFAR = 0;
constexpr int TOKSON = 1;
constexpr int TOKASK = 2;
constexpr int TOKEND = 3;

int judge(string s)
{
    switch (s[0]) {
    case '#':
        return TOKFAR;
    case '+':
        return TOKSON;
    case '?':
        return TOKASK;
    case '$':
        return TOKEND;
    default:
        return -1;
    }
}

map<string, int> direct;
map<int, string> rdirect;
vector<string> S;
int par[50010];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int findpar(int n)
{
    if (par[n] == n) {
        return n;
    } else {
        return par[n] = findpar(par[n]);
    }
}

void unite(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    if (a == b) {
        return;
    }
    printf("unite %s and %s\n", rdirect[a].c_str(), rdirect[b].c_str());
    par[b] = a;
}
void process(const string& far, vector<string>& S)
{
    for (const auto& it : S) {
        unite(direct[far], direct[it]);
    }
    S.clear();
}
int main()
{
    freopen("data/p2814.in", "r", stdin);
    init(50001);
    string str, f;
    int num = 1, type;
    while (true) {
        cin >> str;
        type = judge(str);
        cout << type << ' ' << str << endl;
        if (type == TOKEND) {
            break;
        }
        str = str.substr(1);
        if (direct.find(str) == direct.end()) {
            direct[str] = num;
            rdirect[num] = str;
            num++;
        }
        switch (type) {
        case TOKFAR:
            process(f, S);
            f = str;
            break;
        case TOKSON:
            S.push_back(str);
            break;
        case TOKASK:
            // cout << str << ' ' << rdirect[findpar(direct[str])] << endl;
            break;
        default:;
        }
    }
    for (auto it : direct) {
        cout << it.first << ' ' << rdirect[findpar(direct[it.first])] << endl;
    }
    return 0;
}