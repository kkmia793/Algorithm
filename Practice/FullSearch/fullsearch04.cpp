#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int res = 1e9;
    for (int i = 0; i <= max(x, y); ++i) {
        int cost = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
        res = min(res, cost);
    }

    // for (int i = 0; i <= 2 * max(x, y); i += 2) {
    //     int na = max(0, x - i / 2);
    //     int nb = max(0, y - i / 2);
    //     int cost = i * c + na * a + nb * b;
    //     res = min(res, cost);
    // }

    cout << res << endl;
    return 0;
}
