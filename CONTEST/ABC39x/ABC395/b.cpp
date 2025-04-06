#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> g(n, string(n, '.'));
    for (int i = 0; i < n; ++i) {
        g[i][0] = '#';
        g[i][n-1] = '#';
        g[0][i] = '#';
        g[n-1][i] = '#';
        int j = n - i - 1;
        if (i <= j) {
            char c = (i % 2 == 0) ? '#' : '.';
            for (int x = i; x <= j; ++x) g[i][x] = g[j][x] = c;
            for (int y = i; y <= j; ++y) g[y][i] = g[y][j] = c;
        }
    }
    for (auto& row : g) cout << row << '\n';
    return 0;
}