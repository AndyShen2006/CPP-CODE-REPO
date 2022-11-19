#include "testlib.h"

using namespace std;

struct edge {
    int u, v;
} edges[1000000];

bool vis[1000000];

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    int score = 0;
    int pans = ouf.readInt();
    ouf.readEoln();
    int jans = ans.readInt();
    ans.readEoln();
    if (pans == jans) {
        score += 50;
    }
    pans = ouf.readInt();
    ouf.readEoln();
    jans = ans.readInt();
    ans.readEoln();
    if (pans == jans) {
        score += 50;
    }
    pans = ouf.readInt();
    ouf.readEoln();
    jans = ans.readInt();
    ans.readEoln();
    if (pans == jans) {
        score += 50;
    }
    switch (score) {
    case 0:
        quitf(_wa, "Your answer is not correct");
        break;
    case 50:
        quitp(0.33334, "You finish this problem paritially");
        break;
    case 100:
        quitp(0.66667, "You finish this problem paritially");
        break;
    case 150:
        quitf(_ok, "You finish this problem");
        break;
    default:
        break;
    }
    return 0;
}