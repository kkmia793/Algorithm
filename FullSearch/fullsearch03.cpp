#include <iostream>
#include <string>
using namespace std;

bool isACGTString(const string& s) {
    for (char c : s) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            return false;
        }
    }
    return true;
}

int main() {
    string S;
    cin >> S;

    int max_len = 0;

    for (int i = 0; i < S.length(); ++i) {
        for (int j = 1; j + i <= S.length(); ++j) {
            string sub = S.substr(i, j);
            if (isACGTString(sub)) {
                max_len = max(max_len, j);
            }
        }
    }

    cout << max_len << endl;
    return 0;
}
