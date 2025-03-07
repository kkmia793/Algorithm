#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, D;
    cin >> N >> M >> D;

    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];

    // 1. ソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 2. 2ポインタで探索
    long long p1 = 0, p2 = 0;
    long long ans = -1;  // 条件を満たすペアが見つからなければ -1 のまま

    for (int i = 0; i < N; i++) {
        long long x = A[i];

        // p1 を進めて、B[p1] >= x - D となるようにする
        while (p1 < M && B[p1] < x - D) {
            p1++;
        }
        // p2 を進めて、B[p2] <= x + D となる限り進める
        while (p2 < M && B[p2] <= x + D) {
            p2++;
        }
        // [p1, p2-1] が A[i] と差が D 以内の B の有効範囲
        if (p1 < p2) {
            // 最大の B は B[p2 - 1]
            long long sumVal = x + B[p2 - 1];
            ans = max(ans, sumVal);
        }
    }

    cout << ans << "\n";
    return 0;
}
