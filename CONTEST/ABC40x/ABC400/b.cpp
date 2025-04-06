#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N,M;cin>>N>>M;
    long long s=0,t=1;
    for(int i=0;i<=M;i++){
        if(s+t>1000000000LL){cout<<"inf";return 0;}
        s+=t;
        if(i<M){
            if(t>1000000000LL/N) t=1000000001LL;
            else t*=N;
        }
    }
    cout<<s;
}
