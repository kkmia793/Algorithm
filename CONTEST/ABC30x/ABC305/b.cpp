#include <bits/stdc++.h>
using namespace std;

int d[] = {3, 1, 4, 1, 5, 9};

int main() {
    char p, q;
    cin >> p >> q;

    int a = min(p, q) - 'A';
    int b = max(p, q) - 'A';
    int s = 0;

    for (int i = a; i < b; ++i) s += d[i];

    cout << s << endl;
    
    return 0;
}