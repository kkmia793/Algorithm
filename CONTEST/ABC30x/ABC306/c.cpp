#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pos(n);

    for (int i = 0, x; i < 3 * n; i++) {
        cin >> x;
        pos[x - 1].push_back(i + 1);
    }

    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i + 1;
    
    sort(idx.begin(), idx.end(), [&](int a, int b) { return pos[a - 1][1] < pos[b - 1][1]; });

    for (int i : idx) cout << i << " ";
    cout << endl;
    return 0;
}