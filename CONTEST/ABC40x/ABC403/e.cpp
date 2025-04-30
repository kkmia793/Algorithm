#include <bits/stdc++.h>
using namespace std;
struct ST{
    int n;
    vector<int>s;
    vector<char>lz;
    ST(int x){n=1;while(n<x)n<<=1;s.assign(2*n,0);lz.assign(2*n,0);}
    void app(int i){s[i]=0;lz[i]=1;}
    void push(int i){if(lz[i]){app(i<<1);app(i<<1|1);lz[i]=0;}}
    void upd(int p,int v,int i,int l,int r){
        if(l==r){s[i]+=v;return;}
        push(i);
        int m=(l+r)>>1;
        if(p<=m) upd(p,v,i<<1,l,m);
        else upd(p,v,i<<1|1,m+1,r);
        s[i]=s[i<<1]+s[i<<1|1];
    }
    void upd(int p,int v){upd(p,v,1,1,n);}
    int qry(int L,int R,int i,int l,int r){
        if(R<l||r<L) return 0;
        if(L<=l&&r<=R) return s[i];
        push(i);
        int m=(l+r)>>1;
        return qry(L,R,i<<1,l,m)+qry(L,R,i<<1|1,m+1,r);
    }
    int qry(int L,int R){return qry(L,R,1,1,n);}
    void clr(int L,int R,int i,int l,int r){
        if(R<l||r<L) return;
        if(L<=l&&r<=R){app(i);return;}
        push(i);
        int m=(l+r)>>1;
        clr(L,R,i<<1,l,m);
        clr(L,R,i<<1|1,m+1,r);
        s[i]=s[i<<1]+s[i<<1|1];
    }
    void clr(int L,int R){clr(L,R,1,1,n);}
};
struct FT{
    int n;
    vector<int>f;
    FT(int x):n(x),f(n+1,0){}
    void upd(int i,int v){for(;i<=n;i+=i&-i)f[i]+=v;}
    int sum(int i){int r=0;for(;i>0;i-=i&-i)r+=f[i];return r;}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin>>Q;
    vector<int>T(Q);
    vector<string>S(Q);
    for(int i=0;i<Q;i++)cin>>T[i]>>S[i];

    long long totYlen=0;
    for(int i=0;i<Q;i++)if(T[i]==2)totYlen+=S[i].size();
    vector<array<int,26>> nxt;
    nxt.reserve(totYlen+1);
    nxt.push_back({});
    for(auto &a:nxt)for(int i=0;i<26;i++)a[i]=-1;
    vector<int> yN(Q,-1), xN(Q,-1);

    for(int i=0;i<Q;i++){
        if(T[i]==2){
            int u=0;
            for(char c:S[i]){
                int d=c-'a';
                if(nxt[u][d]<0){
                    nxt[u][d]=nxt.size();
                    nxt.push_back({});
                    for(int j=0;j<26;j++)nxt.back()[j]=-1;
                }
                u=nxt[u][d];
            }
            yN[i]=u;
        }
    }
    for(int i=0;i<Q;i++){
        if(T[i]==1){
            int u=0; bool ok=true;
            for(char c:S[i]){
                int d=c-'a';
                if(nxt[u][d]<0){ok=false;break;}
                u=nxt[u][d];
            }
            if(ok) xN[i]=u;
        }
    }

    int N=nxt.size();
    vector<int> tin(N), tout(N), ci(N,0), stck;
    stck.reserve(N);
    int tm=0;
    stck.push_back(0);
    while(!stck.empty()){
        int u=stck.back();
        if(ci[u]==0) tin[u]=++tm;
        bool pushed=false;
        for(int &i=ci[u];i<26;){
            int c=i++;
            int v=nxt[u][c];
            if(v>=0){stck.push_back(v);pushed=true;break;}
        }
        if(!pushed){
            tout[u]=tm;
            stck.pop_back();
        }
    }

    ST st(tm);
    FT ft(tm+2);
    int um=0;
    vector<int> ans(Q);

    for(int i=0;i<Q;i++){
        if(T[i]==1){
            int u=xN[i];
            if(u>=0){
                int L=tin[u], R=tout[u];
                int c=st.qry(L,R);
                if(c){st.clr(L,R); um-=c;}
                ft.upd(L,1);
                ft.upd(R+1,-1);
            }
        } else {
            int u=yN[i];
            int p=tin[u];
            if(ft.sum(p)==0){
                st.upd(p,1);
                um++;
            }
        }
        ans[i]=um;
    }

    for(int v:ans) cout<<v<<"\n";
    return 0;
}
