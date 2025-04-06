#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long in = a[n / 2];
    long long out = b[n / 2];

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += abs(in - a[i]);
        res += abs(a[i] - b[i]);
        res += abs(b[i] - out);
    }

    cout << res << endl;
    return 0;
}
