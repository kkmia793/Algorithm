#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    
    vector<long long> b(n), w(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    sort(b.begin(), b.end(), greater<long long>());
    sort(w.begin(), w.end(), greater<long long>());

    vector<long long> pb(n + 1, 0), pw(m + 1, 0);
    for (int i = 0; i < n; i++) pb[i + 1] = pb[i] + b[i];
    for (int i = 0; i < m; i++) pw[i + 1] = pw[i] + w[i];

    vector<long long> mb(n + 1);
    mb[n] = pb[n];
    for (int i = n - 1; i >= 0; i--) mb[i] = max(mb[i + 1], pb[i]);

    long long ans = 0;
    int lim = min((int)n, (int)m);
    for (int j = 0; j <= lim; j++) ans = max(ans, mb[j] + pw[j]);

    cout << ans << "\n";
}
