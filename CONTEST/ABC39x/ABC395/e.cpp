#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
using ll = long long;

static const ll INF = LLONG_MAX / 4;

struct S {
    ll c;
    int v, m;
    bool operator>(const S &o) const { return c > o.c; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> g0(n+1), g1(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g0[u].push_back(v);
        g1[v].push_back(u);
    }

    vector<vector<ll>> d(2, vector<ll>(n+1, INF));
    d[0][1] = 0;

    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        S s = pq.top(); pq.pop();
        if(s.c > d[s.m][s.v]) continue;

        const auto &nl = (s.m == 0 ? g0[s.v] : g1[s.v]);
        for(int nv : nl){
            ll nc = s.c + 1;
            if(nc < d[s.m][nv]){
                d[s.m][nv] = nc;
                pq.push({nc, nv, s.m});
            }
        }

        int fm = 1 - s.m;
        ll fc = s.c + x;
        if(fc < d[fm][s.v]){
            d[fm][s.v] = fc;
            pq.push({fc, s.v, fm});
        }
    }

    ll ans = min(d[0][n], d[1][n]);
    cout << ans << "\n";
    return 0;
}
