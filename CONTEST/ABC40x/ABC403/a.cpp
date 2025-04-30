#include <iostream>
using namespace std;

int main() {
    int n, a, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (i % 2 == 1) s += a;
    }
    cout << s << endl;
}
