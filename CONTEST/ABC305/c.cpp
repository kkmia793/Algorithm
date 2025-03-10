#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> s;

int main() {
    cin >> h >> w;
    s.resize(h);

    for (int i = 0; i < h; ++i) cin >> s[i];

    int r1 = h, r2 = 0, c1 = w, c2 = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                r1 = min(r1, i);
                r2 = max(r2, i);
                c1 = min(c1, j);
                c2 = max(c2, j);
            }
        }
    }

    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            if (s[i][j] == '.') {
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
