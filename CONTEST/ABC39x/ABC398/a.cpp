#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s(n, '-');
    if (n % 2 == 0) {
        s[n / 2 - 1] = '=';
        s[n / 2] = '=';
    } else {
        s[n / 2] = '=';
    }
    cout << s << endl;
    return 0;
}
