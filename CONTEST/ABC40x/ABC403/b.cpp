#include <iostream>
#include <string>
using namespace std;

int main() {
    string t, u;
    cin >> t >> u;
    int n = t.size(), m = u.size();
    
    for (int i = 0; i + m <= n; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (t[i + j] != '?' && t[i + j] != u[j]) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
