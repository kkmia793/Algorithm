#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;

    vector<long long>a(n);for(int i=0;i<n;i++)cin>>a[i];
    vector<long long>e(n);

    for(int i=0;i<n-1;i++)e[i+1]=e[i]+((i%2)?a[i+1]-a[i]:0);

    auto f=[&](long long x){

        if(x<=a[0])return 0LL;
        if(x>=a[n-1])return e[n-1];

        int i=int(upper_bound(a.begin(),a.end(),x)-a.begin())-1;

        long long r=e[i];

        if(i%2)r+=x-a[i];

        return r;
    };
    
    int q;cin>>q;
    while(q--){
        long long l,r;cin>>l>>r;
        cout<<f(r)-f(l)<<"\n";
    }
    return 0;
}
