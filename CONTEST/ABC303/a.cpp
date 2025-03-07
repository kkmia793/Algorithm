#include <iostream>
#include <string>
using namespace std;

bool sim(char x, char y) {
    if (x == y) return true;
    if ((x == '1' && y == 'l') || (x == 'l' && y == '1')) return true;
    if ((x == '0' && y == 'o') || (x == 'o' && y == '0')) return true;
    return false;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (!sim(s[i], t[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
