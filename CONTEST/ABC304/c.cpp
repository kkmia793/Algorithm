#include <bits/stdc++.h>

using namespace std;

int n, d;
vector<pair<int, int>> p;
vector<bool> inf;

void dfs(int i) {
    for (int j = 0; j < n; ++j) {
        if (!inf[j]) {
            int dx = p[i].first - p[j].first;
            int dy = p[i].second - p[j].second;
            if (dx * dx + dy * dy <= d * d) {
                inf[j] = true;
                dfs(j);
            }
        }
    }
}

int main() {
    cin >> n >> d;
    p.resize(n);
    inf.resize(n, false);

    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

    inf[0] = true;
    dfs(0);
    
    for (int i = 0; i < n; ++i) cout << (inf[i] ? "Yes" : "No") << endl;
    return 0;
}
