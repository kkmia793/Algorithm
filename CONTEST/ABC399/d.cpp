#include <bits/stdc++.h>
using namespace std;

// あとで
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(2 * N);
        for (int i = 0; i < 2 * N; i++) cin >> A[i];

        vector<vector<int>> position(N + 1);
        for (int i = 0; i < 2 * N; i++) {
            position[A[i]].push_back(i);
        }

        set<pair<int, int>> answers;

        for (int i = 0; i + 1 < 2 * N; i++) {
            int a = A[i], b = A[i + 1];

            if (position[a][0] + 1 == position[a][1]) continue;
            if (position[b][0] + 1 == position[b][1]) continue;

            vector<int> indices = {position[a][0], position[a][1],
                                   position[b][0], position[b][1]};
            sort(indices.begin(), indices.end());

            if (indices[0] + 1 == indices[1] && indices[2] + 1 == indices[3]) {
                answers.emplace(min(a, b), max(a, b));
            }
        }

        cout << answers.size() << "\n";
    }

    return 0;
}
