#include <bits/stdc++.h>
using namespace std;

struct EdgeInfo {
    long long forwardCount = 0;
    long long backwardCount = 0;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long selfLoopCount = 0;
    unordered_map<long long, EdgeInfo> mp;
    mp.reserve(M);

    auto encodePair = [&](int a, int b) {
        return (static_cast<long long>(a) << 20) + b;
    };

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        if(u == v){
            selfLoopCount++;
        } else {
            int x = min(u, v);
            int y = max(u, v);
            long long key = encodePair(x, y);
            if(u < v){
                mp[key].forwardCount++;
            } else {
                mp[key].backwardCount++;
            }
        }
    }

    long long ans = 0;
    ans += selfLoopCount;

    for(const auto &p : mp){
        const auto &info = p.second;
        long long c1 = info.forwardCount;
        long long c2 = info.backwardCount;
        if(c1 > 0 && c2 > 0){
            ans += (c1 + c2 - 1);
        } else {
            long long c = c1 + c2;
            ans += (c - 1);
        }
    }

    cout << ans << "\n";
    return 0;
}