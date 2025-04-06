#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < 1000; ++i) {
        string t = to_string(i);
        while (t.length() < 3) t = "0" + t;
        int idx = 0;
        for (char c : s) {
            if (c == t[idx]) ++idx;
            if (idx == 3) break;
        }
        if (idx == 3) ++cnt;
    }

    cout << cnt << endl;
    return 0;
}
