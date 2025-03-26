#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<tuple<ll, ll, int>> v(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, a + b, i + 1};
    }

    sort(v.begin(), v.end(), [](const auto& x, const auto& y) {
        ll a1, b1, i1;
        ll a2, b2, i2;
        tie(a1, b1, i1) = x;
        tie(a2, b2, i2) = y;
        if (a1 * b2 != a2 * b1) return a1 * b2 > a2 * b1;
        return i1 < i2;
    });

    for (auto& [a, b, i] : v) cout << i << " ";
    cout << endl;
}
