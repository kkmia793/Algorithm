#include <bits/stdc++.h>

using namespace std;

int n, m;

bool canSwap(string a, string b) {
    int diffCount = 0;

    for (int index = 0; index < m; ++index) {
        if (a[index] != b[index]) {
            diffCount++;
        }
    }

    return diffCount == 1;
}

int main() {
    cin >> n >> m;

    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    do {
        bool isValid = true;

        for (int j = 1; j < n; ++j) {
            if (!canSwap(s[j - 1], s[j])) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << "Yes" << endl;
            return 0;
        }

    } while (next_permutation(s.begin(), s.end()));

    cout << "No" << endl;

    return 0;
}
