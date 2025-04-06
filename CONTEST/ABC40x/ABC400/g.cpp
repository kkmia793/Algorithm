#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct C { ll x,y,z,s,A,B,Cc; };
 
const ll INF = -LLONG_MAX/2;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        vector<C> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].x >> v[i].y >> v[i].z;
            v[i].s = v[i].x + v[i].y + v[i].z;
            v[i].A = v[i].x - v[i].y - v[i].z;
            v[i].B = v[i].y - v[i].x - v[i].z;
            v[i].Cc = v[i].z - v[i].x - v[i].y;
        }
        sort(v.begin(), v.end(), [](auto &p, auto &q){ return p.s < q.s; });
        int m = 2*k;
        ll ans = 0;
        for(int st = 0; st <= n - m; st++){
            vector<C> a(v.begin()+st, v.begin()+st+m);
            int L = m;
            vector<vector<ll>> dp(L+1, vector<ll>(L+1, INF));
            dp[0][0]=0;
            for(int i=0;i<L;i++){
                for(int j=0;j<=L;j++){
                    if(dp[i][j]==INF) continue;
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i].s);
                    if(j>0){
                        int idx = i - j;
                        ll f = max({ a[i-j].A + a[i].A, a[i-j].B + a[i].B, a[i-j].Cc + a[i].Cc });
                        dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + a[i].s + f);
                    }
                }
            }
            ans = max(ans, dp[L][0]);
        }
        cout << ans/2 << "\n";
    }
    return 0;
}
