#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;
vector<string> grid;

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}; 
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

string target = "snuke";

bool inBounds(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

void solve() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int d = 0; d < 8; d++) {
                vector<pair<int, int>> positions;
                bool match = true;
                
                for (int k = 0; k < 5; k++) {
                    int ni = i + dx[d] * k;
                    int nj = j + dy[d] * k;
                    
                    if (!inBounds(ni, nj) || grid[ni][nj] != target[k]) {
                        match = false;
                        break;
                    }
                    positions.push_back({ni + 1, nj + 1}); // 1-indexed
                }
                
                if (match) {
                    for (auto pos : positions) {
                        cout << pos.first << " " << pos.second << endl;
                    }
                    return; 
                }
            }
        }
    }
}

int main() {
    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    solve();
    return 0;
}
