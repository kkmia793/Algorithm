#include <bits/stdc++.h>

using namespace std;

int main() {
    long long w, h, n, a, b;
    cin >> w >> h >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

    cin >> a;
    vector<int> x(a);
    for (int i = 0; i < a; ++i) cin >> x[i];
    cin >> b;

    vector<int> y(b);
    for (int i = 0; i < b; ++i) cin >> y[i];

    map<pair<int, int>, int> m;

    for (auto [px, py] : p) {
        int xi = lower_bound(x.begin(), x.end(), px) - x.begin();
        int yi = lower_bound(y.begin(), y.end(), py) - y.begin();
        m[{xi, yi}]++;
    }

    int mn = INT_MAX, mx = 0;

    for (auto [k, v] : m) {
        mn = min(mn, v);
        mx = max(mx, v);
    }

    if (m.size() < (a + 1) * (b + 1)) mn = 0;

    cout << mn << ' ' << mx << endl;
    
    return 0;
}
