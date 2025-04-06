#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    for (int i = 0, a; i < 7; ++i) {
        cin >> a;
        m[a]++;
    }
    for (auto &[x, cx] : m) {
        for (auto &[y, cy] : m) {
            if (x != y && ((cx >= 3 && cy >= 2) || (cx >= 2 && cy >= 3))) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
