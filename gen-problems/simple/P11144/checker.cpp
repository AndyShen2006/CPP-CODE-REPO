#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

int main(int argc, char** argv)
{
    registerInteraction(argc, argv);
    int n = inf.readInt(); // 选数
    cout.flush(); // 刷新缓冲区
    int left = 50;
    bool found = false;
    while (left > 0 && !found) {
        left--;
        int a = ouf.readInt(1, 1000000000); // 询问
        if (a < n)
            cout << 0 << endl;
        else if (a > n)
            cout << 2 << endl;
        else
            cout << 1 << endl, found = true;
        cout.flush();
    }
    if (!found)
        quitf(_wa, "couldn't guess the number with 50 questions");
    ouf.readEof();
    quitf(_ok, "guessed the number with %d questions!", 50 - left);
}