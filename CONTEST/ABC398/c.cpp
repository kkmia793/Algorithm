#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    unordered_map<long long, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    long long mx = -1;
    int res = -1;
    for (int i = 0; i < n; ++i) {
        if (m[a[i]] == 1 && a[i] > mx) {
            mx = a[i];
            res = i + 1;
        }
    }
    cout << res << endl;
    return 0;
}
