#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int n, m;
vector<vector<pair<int, ull>>> g;
ull ans = ULLONG_MAX;

void dfs(int u, int mask, ull x) {
    if (u == n - 1) {
        ans = min(ans, x);
        return;
    }
    for (auto& p : g[u]) {
        int v = p.first;
        if (mask & (1 << v)) continue;
        dfs(v, mask | (1 << v), x ^ p.second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ull w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(0, 1, 0);
    cout << ans;
}
