#include <iostream>
#include <vector>
using namespace std;

int H, W;
vector<string> grid;

bool canPlaceX(int x, int y, int n) {
    if (x - n < 0 || x + n >= H || y - n < 0 || y + n >= W) return false;

    if (grid[x][y] != '#') return false;

    for (int d = 1; d <= n; ++d) {
        if (grid[x + d][y + d] != '#' || grid[x + d][y - d] != '#') return false;
        if (grid[x - d][y + d] != '#' || grid[x - d][y - d] != '#') return false;
    }
    return true;
}

int main() {
    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int N = min(H, W);
    vector<int> result(N, 0);

    for (int n = N - 1; n >= 1; --n) {
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (canPlaceX(i, j, n)) {
                    result[n - 1]++;
                    grid[i][j] = '.';
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << (i < N - 1 ? " " : "\n");
    }

    return 0;
}
