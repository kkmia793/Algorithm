#include <iostream>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) ++c;
    }
    cout << c << endl;
    return 0;
}
