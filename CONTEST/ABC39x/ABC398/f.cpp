#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());

    string t = r + '#' + s;
    vector<int> p(t.size());

    for (int i = 1; i < (int)t.size(); i++) {
        int j = p[i - 1];
        while (j > 0 && t[i] != t[j]) j = p[j - 1];
        if (t[i] == t[j]) j++;
        p[i] = j;
    }

    cout << s << r.substr(p.back()) << "\n";
}
