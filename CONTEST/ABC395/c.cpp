#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    unordered_map<int, int> p;
    int l = 0, m = n + 1;
    for (int r = 0; r < n; ++r) {
        if (p.count(a[r]) && p[a[r]] >= l) {
            m = min(m, r - p[a[r]] + 1);
            l = p[a[r]] + 1;
        }
        p[a[r]] = r;
    }
    cout << (m == n + 1 ? -1 : m) << '\n';
    return 0;
}