#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 2ポインタ法

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    long long mindiff = 1e18;

    while (i < n && j < m) {
        long long diff = abs(a[i] - b[j]);
        mindiff = min(mindiff, diff);

        if (a[i] < b[j]) ++i;
        else ++j;
    }

    cout << mindiff << endl;
    return 0;
}
