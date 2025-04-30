#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;
    vector<char>a(n+1);
    unordered_set<ull> h;
    h.reserve(q);
    while(q--){
        int t,x,y;
        cin>>t>>x;
        if(t==1){
            cin>>y;
            if(!a[x]) h.insert((ull(x)<<32)|y);
        } else if(t==2){
            a[x]=1;
        } else {
            cin>>y;
            ull k=(ull(x)<<32)|y;
            cout<<(a[x]||h.count(k)?"Yes":"No")<<"\n";
        }
    }
    return 0;
}
