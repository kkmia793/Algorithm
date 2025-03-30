#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), r(n, 0);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int x = 1;
    while (true) {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (r[i] == 0) mx = max(mx, p[i]);
        }
        if (mx == -1) break;

        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == mx && r[i] == 0) {
                r[i] = x;
                ++c;
            }
        }
        x += c;
    }

    for (int i = 0; i < n; ++i) cout << r[i] << endl;
    return 0;
}
