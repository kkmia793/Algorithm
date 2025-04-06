#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> s;
string t = "snuke";
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
    cin >> h >> w;
    s.resize(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    if (s[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<bool>> vis(h, vector<bool>(w));
    queue<tuple<int, int, int>> q;
    vis[0][0] = true;
    q.emplace(0, 0, 0);

    while (!q.empty()) {
        auto [x, y, k] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            int nk = (k + 1) % 5;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (vis[nx][ny]) continue;
            if (s[nx][ny] != t[nk]) continue;
            vis[nx][ny] = true;
            q.emplace(nx, ny, nk);
        }
    }

    cout << (vis[h - 1][w - 1] ? "Yes" : "No") << endl;
}
