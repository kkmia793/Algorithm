#include <bits/stdc++.h>
using namespace std;

//あとで

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> to(26, -1);
    vector<bool> u(26, false);

    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        u[a] = true;
        if (to[a] < 0) {
            to[a] = b;
        } else if (to[a] != b) {
            cout << -1 << "\n";
            return 0;
        }
    }

    vector<int> g(26, -1);
    int e = 0;

    for (int i = 0; i < 26; i++) {
        if (to[i] >= 0 && to[i] != i) {
            g[i] = to[i];
            e++;
        }
    }

    vector<int> col(26, 0);
    int sc = 0;

    function<void(int)> dfs = [&](int x) {
        col[x] = 1;
        int y = g[x];
        if (y >= 0) {
            if (col[y] == 0) dfs(y);
            else if (col[y] == 1) sc++;
        }
        col[x] = 2;
    };

    for (int i = 0; i < 26; i++) {
        if (col[i] == 0 && g[i] >= 0) dfs(i);
    }

    int used = 0;
    for (int i = 0; i < 26; i++) {
        if (u[i]) used++;
    }

    if (sc > 0 && used == 26) {
        cout << -1 << "\n";
        return 0;
    }

    cout << e + sc << "\n";
    return 0;
}
