#include <iostream>
#include <string>

using namespace std;

int main() {
    string S, result;
    cin >> S;

    for (char c : S) {
        if (c == '2') {
            result += c;
        }
    }

    cout << result << endl;
    return 0;
}