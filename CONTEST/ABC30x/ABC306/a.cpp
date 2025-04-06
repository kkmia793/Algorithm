#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (char c : s) cout << c << c;
    cout << endl;
    
    return 0;
}