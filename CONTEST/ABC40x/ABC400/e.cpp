#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MX = 4000000000000LL, L = 2000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isPrime(L + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= L; i++){
        if(isPrime[i])
            for (int j = i * i; j <= L; j += i)
                isPrime[j] = false;
    }

    vector<int> pr;
    for (int i = 2; i <= L; i++){
        if(isPrime[i]) pr.push_back(i);
    }
    vector<ll> v;
    int n = pr.size();

    for (int i = 0; i < n && (ll)pr[i]*pr[i] <= L; i++){
        int p = pr[i];
        ll pp = 1;
        for (int e = 1;; e++){
            pp *= p;
            if (pp > L) break;
            for (int j = i + 1; j < n; j++){
                int q = pr[j];
                if (q > L / pp) break;
                ll qq = 1;
                for (int f = 1;; f++){
                    qq *= q;
                    if (pp * qq > L) break;
                    v.push_back((pp * qq) * (pp * qq));
                }
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int Q; cin >> Q;
    while (Q--){
        ll A; cin >> A;
        auto it = upper_bound(v.begin(), v.end(), A);
        if (it == v.begin()) cout << 0 << "\n";
        else { it--; cout << *it << "\n"; }
    }
    
    return 0;
}
