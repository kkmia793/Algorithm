#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
};

struct H {
    size_t operator()(const P& a) const {
        auto h1 = (1ULL << 31) ^ ((unsigned long long)(a.x) ^ ((unsigned long long)(a.y) << 32));
        h1 ^= h1 >> 23; h1 ^= (h1 << 7); h1 ^= h1 >> 17;
        h1 ^= (h1 << 5); h1 ^= h1 >> 11; h1 ^= (h1 << 13);
        return (size_t)h1;
    }
};

struct E {
    bool operator()(const P& a, const P& b) const {
        return a.x == b.x && a.y == b.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;

    vector<int> x(n + 1), y(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            x[i + 1] = x[i] - 1;
            y[i + 1] = y[i];
        }
        if (s[i] == 'S') {
            x[i + 1] = x[i] + 1;
            y[i + 1] = y[i];
        }
        if (s[i] == 'W') {
            x[i + 1] = x[i];
            y[i + 1] = y[i] - 1;
        }
        if (s[i] == 'E') {
            x[i + 1] = x[i];
            y[i + 1] = y[i] + 1;
        }
    }

    unordered_set<P, H, E> st;
    st.reserve(n + 1);
    st.insert({0, 0});

    string ans(n, '0');
    for (int t = 1; t <= n; t++) {
        P cur = {x[t], y[t]};
        if (!st.count(cur)) st.insert(cur);
        P need = {x[t] - r, y[t] - c};
        if (st.count(need)) ans[t - 1] = '1';
    }

    cout << ans << "\n";
}
