#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
ll x, ts = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    ll *u = new ll[n];
    ll *d = new ll[n];
    ll ms = 1LL << 60;

    for (int i = 0; i < n; i++){
        cin >> u[i] >> d[i];
        ll s = u[i] + d[i];
        ts += s;
        ms = min(ms, s);
    }
    
    auto f = [&](ll h) -> bool {
        ll cl, ch;
        ll l = max(1LL, h - d[0]);
        ll r = min(u[0], h - 1);
        if(l > r) return false;
        cl = l; ch = r;
        for (int i = 1; i < n; i++){
            l = max(1LL, h - d[i]);
            r = min(u[i], h - 1);
            if(l > r) return false;
            ll nl = max(l, cl - x);
            ll nh = min(r, ch + x);
            if(nl > nh) return false;
            cl = nl; ch = nh;
        }
        return true;
    };
    
    ll lo = 2, hi = ms, ah = 2;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(f(mid)){
            ah = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    ll c = ts - n * ah;
    cout << c << "\n";
    
    delete[] u;
    delete[] d;
    return 0;
}