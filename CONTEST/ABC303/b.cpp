#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            bool ok = false;
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < n - 1; ++l) {
                    if ((p[k][l] == i && p[k][l + 1] == j) || (p[k][l] == j && p[k][l + 1] == i)) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (!ok) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
