#include "testlib.h"

using namespace std;

vector<pair<string, double>> pans;
vector<pair<string, double>> jans;

int main(int argc, char** argv)
{
    registerTestlibCmd(argc, argv);
    double psrks = ouf.readDouble();
    double jsrks = ans.readDouble();
    if (fabs(psrks - jsrks) > 0.02) {
        quitf(_wa, "The answer is wrong: expected:%f, found: %f", jsrks, psrks);
        exit(0);
    }
    while (!ans.eof()) {
        string pstr = ouf.readToken();
        double prks = ouf.readDouble();
        pans.push_back(make_pair(pstr, prks));
        ouf.readEoln();
        string jstr = ans.readToken();
        double jrks = ans.readDouble();
        jans.push_back(make_pair(jstr, jrks));
        ans.readEoln();
    }
    stable_sort(pans.begin(), pans.end());
    stable_sort(jans.begin(), jans.end());
    if (pans.size() > jans.size()) {
        quitf(_wa, "Your answer is too long");
        exit(0);
    }
    if (pans.size() < jans.size()) {
        quitf(_wa, "Your answer is too short");
        exit(0);
    }
    for (int i = 0; i < pans.size(); i++) {
        if (pans[i].first != jans[i].first || fabs(pans[i].second - jans[i].second) > 0.02) {
            quitf(_wa, "The answer is wrong on line %d, expected: %s %f, found: %s %f", i + 2, jans[i].first.c_str(), jans[i].second, pans[i].first.c_str(), pans[i].second);
            exit(0);
        }
    }
    quitf(_ok, "The answer is correct.You will ak IOI");
    return 0;
}