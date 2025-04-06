#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> orig(H), cur(H);
    for (int i = 0; i < H; i++) {
        cin >> orig[i];
        cur[i] = orig[i];
    }

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;

    const int INF = 1e9;
    vector<vector<int>> d(H, vector<int>(W, INF));
    vector<vector<bool>> conv(H, vector<bool>(W, false));
    deque<pair<int, int>> dq;

    d[A][B] = 0;
    dq.push_back({A, B});

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        int c = d[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (orig[nx][ny] == '.' && c < d[nx][ny]) {
                d[nx][ny] = c;
                dq.push_front({nx, ny});
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int k = 1; k <= 2; k++) {
                int nx = x + dx[i] * k, ny = y + dy[i] * k;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) break;
                if (c + 1 < d[nx][ny]) {
                    d[nx][ny] = c + 1;
                    dq.push_back({nx, ny});
                    if (orig[nx][ny] == '#' && !conv[nx][ny]) {
                        conv[nx][ny] = true;
                        cur[nx][ny] = '.';
                    }
                }
            }
        }
    }

    cout << d[C][D] << '\n';
    return 0;
}
