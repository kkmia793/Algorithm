#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string res;
    stack<int> st;

    for (char c : s) {
        if (c == '(') {
            st.push(res.size());
        }
        if (c == ')' && !st.empty()) {
            res.erase(st.top());
            st.pop();
            continue;
        }
        res += c;
    }

    cout << res << endl;
    return 0;
}
