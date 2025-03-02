#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isColorfulBracketSequence(const string &s) {
    stack<char> stk;
    
    for (char c : s) {
        if (!stk.empty() && (
            (stk.top() == '(' && c == ')') ||
            (stk.top() == '[' && c == ']') ||
            (stk.top() == '<' && c == '>')
        )) {
            stk.pop(); 
        } else {
            stk.push(c); 
        }
    }
    
    return stk.empty(); 
}

int main() {
    string s;
    cin >> s;
    
    if (isColorfulBracketSequence(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}