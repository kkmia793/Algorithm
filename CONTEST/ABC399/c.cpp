#include <iostream>
#include <vector>
using namespace std;

struct UF {
    vector<int> p;
    UF(int n) : p(n, -1) {}
    int f(int x) {
        if (p[x] < 0) return x;
        return p[x] = f(p[x]);
    }
    bool u(int x, int y) {
        x = f(x); y = f(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UF uf(n + 1);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (!uf.u(a, b)) ++ans;
    }
    cout << ans << endl;
    return 0;
}
