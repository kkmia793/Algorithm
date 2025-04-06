#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, r = 0;
    cin >> n;
    for (int k = 1; k <= 60; k++){
        long long d = 1LL << k;
        if(d > n) break;
        long long t = n / d;
        long long y = floor(sqrt((long double)t));
        r += (y + 1) / 2;
    }
    cout << r;
    return 0;
}
