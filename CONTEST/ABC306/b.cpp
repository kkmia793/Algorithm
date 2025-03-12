#include <iostream>
using namespace std;

int main() {
    long long r = 0, p = 1;
    for (int i = 0, x; i < 64; i++, p <<= 1) {
        cin >> x;
        r += x * p;
    }
    cout << r << endl;
    return 0;
}