#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, string>> p;

int main() {
    cin >> n;
    p.resize(n);

    for (int i = 0; i < n; ++i) cin >> p[i].second >> p[i].first;

    int s = min_element(p.begin(), p.end())->first;
    int idx = 0;

    for (int i = 0; i < n; ++i) {
        if (p[i].first == s) {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i) cout << p[(idx + i) % n].second << endl;
    
    return 0;
}