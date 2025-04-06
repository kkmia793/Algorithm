#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> g(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        if (x == y) {
            if (z != 0) {
                cout << "-1\n";
                return 0;
            }
            continue;
        }
        g[x].push_back({y, (int)z});
        g[y].push_back({x, (int)z});
    }

    vector<int> vs(N + 1, 0), xv(N + 1, 0), ans(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (!vs[i]) {
            vector<int> st(1, i), c;
            vs[i] = 1;
            xv[i] = 0;

            while (!st.empty()) {
                int u = st.back();
                st.pop_back();
                c.push_back(u);

                for (auto &e : g[u]) {
                    int v = e.first, w = e.second;
                    if (!vs[v]) {
                        vs[v] = 1;
                        xv[v] = xv[u] ^ w;
                        st.push_back(v);
                    } else if (xv[v] != (xv[u] ^ w)) {
                        cout << "-1\n";
                        return 0;
                    }
                }
            }

            int s = c.size(), rv = 0;
            for (int b = 0; b < 31; b++) {
                int cnt = 0;
                for (auto &d : c) if ((xv[d] >> b) & 1) cnt++;
                if (cnt > (s - cnt)) rv |= (1 << b);
            }
            for (auto &d : c) ans[d] = rv ^ xv[d];
        }
    }

    for (int i = 1; i <= N; i++) 
        cout << ans[i] << (i == N ? '\n' : ' ');

    return 0;
}
