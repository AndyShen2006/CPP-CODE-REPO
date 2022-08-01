#include "testlib.h"

using namespace std;

struct edge {
    int u, v;
} edges[1000000];

bool vis[1000000];

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    string pstr = ouf.readToken();
    string jstr = ans.readToken();
    if (pstr != jstr) {
        quitf(_wa, "The answer is wrong: expected:%s, found:%s", jstr.c_str(), pstr.c_str());
    }
    inf.readInt();
    int cntEdge = inf.readInt();
    for (int i = 1; i <= cntEdge; i++) {
        edges[i].u = inf.readInt();
        edges[i].v = inf.readInt();
        inf.readEoln();
    }
    int crt;
    int e = ouf.readInt();
    if (e > 0) {
        crt = edges[abs(e)].v;
    } else {
        crt = edges[abs(e)].u;
    }
    vis[abs(e)] = true;
    while (!ouf.eof()) {
        e = ouf.readInt();
        ouf.readSpace();
        if (vis[abs(e)]) {
            quitf(_wa, "The answer is wrong:You have find this edge just now");
        } else {
            if (e > 0) {
                if (crt != edges[abs(e)].u) {
                    quitf(_wa, "You can't find this edge");
                } else {
                    crt = edges[abs(e)].v;
                }
            } else {
                if (crt != edges[abs(e)].v) {
                    quitf(_wa, "You can't find this edge");
                } else {
                    crt = edges[abs(e)].u;
                }
            }
        }
    };
    quitf(_ok, "The answer is correct, you will AK IOI!");
    return 0;
}