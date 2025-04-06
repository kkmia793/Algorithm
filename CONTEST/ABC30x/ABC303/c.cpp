#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m, h, k, x = 0, y = 0;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> it;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        it.insert({a, b});
    }

    for (char c : s) {
        h--;
        if (c == 'R') x++;
        if (c == 'L') x--;
        if (c == 'U') y++;
        if (c == 'D') y--;

        if (h < 0) {
            cout << "No";
            return 0;
        }

        if (h < k && it.count({x, y})) {
            h = k;
            it.erase({x, y});
        }
    }
    cout << "Yes";
    return 0;
}
