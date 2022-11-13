#include <bits/stdc++.h>

using namespace std;

constexpr int air = 0;
constexpr int mud = 1;
constexpr int source_water = 2;
constexpr int new_water = 3;

int world[25][25];
int n, m, k;
void showWorld()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (world[i][j] == new_water) {
                cout << 2 << ' ';
                continue;
            }
            cout << world[i][j] << ' ';
        }
        cout << endl;
    }
}

void update()
{
    vector<pair<int, int>> source_waters;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Step1:Remove all new-water
            if (world[i][j] == new_water) {
                world[i][j] = air;
            }
            // Step2:Find all source-water
            if (world[i][j] == source_water) {
                source_waters.push_back(make_pair(i, j));
            }
        }
    }
    // Step3:Let source-water move
    for (auto it : source_waters) {
        for (int i = it.first + 1; i <= m; i++) {
            if (world[i][it.second] == mud) {
                break;
            }
            if (world[i][it.second] == air) {
                world[i][it.second] = new_water;
            }
            if (world[i][it.second] == source_water) {
                world[i][it.second] = new_water;
            }
        }
    }
}

int main()
{
    // freopen("data/god.in", "r", stdin);
    //  Input
    cin >> n >> m >> k;
    // Compute Changes
    string op;
    int row, col;
    for (int i = 1; i <= k; i++) {
        cin >> op >> row >> col;
        if (op == "air") {
            world[row][col] = air;
        } else if (op == "mud") {
            world[row][col] = mud;
        } else {
            world[row][col] = source_water;
        }
        update();
        // showWorld();
        // cout << endl;
    }
    showWorld();
    return 0;
}