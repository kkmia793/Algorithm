#include <bits/stdc++.h>
using namespace std;

static const long long NEG_INF = LLONG_MIN;

// dp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long dp0 = 0, dp1 = NEG_INF;

    for (int i = 0; i < N; i++) {
        int x;
        long long y;
        cin >> x >> y;

        long long ndp0 = NEG_INF, ndp1 = NEG_INF;

        ndp0 = max(ndp0, dp0);
        ndp1 = max(ndp1, dp1);

        if (x == 0) {
            if (dp0 != NEG_INF) ndp0 = max(ndp0, dp0 + y);
            if (dp1 != NEG_INF) ndp0 = max(ndp0, dp1 + y);
        } else {
            if (dp0 != NEG_INF) ndp1 = max(ndp1, dp0 + y);
        }

        dp0 = ndp0;
        dp1 = ndp1;
    }

    cout << max({dp0, dp1, 0LL}) << "\n";
    return 0;
}
