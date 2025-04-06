#include <bits/stdc++.h>
using namespace std;
// 逆元
static const long long M = 998244353;

static long long pp[200001][11], S[11][200002], f[11], fi[11];

long long inv(long long x) {
    long long r = 1, e = M - 2;
    while (e > 0) {
        if (e & 1) r = (r * x) % M;
        x = (x * x) % M;
        e >>= 1;
    }
    return r;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return f[n] * fi[r] % M * fi[n - r] % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[i + 1] = (p[i] + a[i]) % M;
    }

    f[0] = 1;
    for (int i = 1; i <= k; i++) f[i] = f[i - 1] * i % M;

    fi[k] = inv(f[k]);
    for (int i = k - 1; i >= 0; i--) {
        fi[i] = fi[i + 1] * (i + 1) % M;
    }

    vector<long long> c(k + 1);
    for (int i = 0; i <= k; i++) c[i] = nCr(k, i);

    for (int r = 0; r <= n; r++) {
        long long x = p[r], t = 1;
        for (int m = 0; m <= k; m++) {
            if (m == 0) pp[r][m] = 1;
            else {
                t = (t * x) % M;
                pp[r][m] = t;
            }
        }
    }

    for (int m = 0; m <= k; m++) {
        S[m][0] = pp[0][m];
        for (int r = 1; r <= n; r++) {
            S[m][r] = (S[m][r - 1] + pp[r][m]) % M;
        }
    }

    long long ans = 0;
    for (int r = 1; r <= n; r++) {
        for (int m = 0; m <= k; m++) {
            long long sgn = (m % 2 ? M - 1 : 1);
            long long val = c[m] * sgn % M * pp[r][k - m] % M * S[m][r - 1] % M;
            ans = (ans + val) % M;
        }
    }

    cout << ans << "\n";
}
