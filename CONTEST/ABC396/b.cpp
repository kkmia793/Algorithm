#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q, c, x;
    stack<int> s;
    for (int i = 0; i < 100; i++) s.push(0);
    cin >> q;
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> x;
            s.push(x);
        } else {
            cout << s.top() << endl;
            s.pop();
        }
    }
    return 0;
}