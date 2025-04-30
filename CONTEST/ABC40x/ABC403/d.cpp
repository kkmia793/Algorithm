#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long D;
    cin >> N >> D;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    if(D == 0){
        sort(A.begin(), A.end());
        int uniq = 0;
        for(int i = 0; i < N; i++){
            if(i == 0 || A[i] != A[i-1]) uniq++;
        }
        cout << N - uniq;
        return 0;
    }

    sort(A.begin(), A.end());

    vector<pair<long long,int>> C;
    for(auto x : A){
        if(C.empty() || C.back().first != x) C.emplace_back(x,1);
        else C.back().second++;
    }

    int M = C.size();
    unordered_map<long long,int> mp;
    mp.reserve(M * 2);
    for(int i = 0; i < M; i++){
        mp[C[i].first] = i;
    }

    long long keep = 0;
    vector<long long> chain;

    for(int i = 0; i < M; i++){
        if(mp.count(C[i].first - D)) continue;
        chain.clear();
        int cur = i;
        while(true){
            chain.push_back(C[cur].second);
            auto it = mp.find(C[cur].first + D);
            if(it == mp.end()) break;
            cur = it->second;
        }
        int K = chain.size();
        if(K == 1){
            keep += chain[0];
        } else {
            long long p0 = chain[0];
            long long p1 = max(chain[0], chain[1]);
            for(int t = 2; t < K; t++){
                long long p2 = max(p1, p0 + chain[t]);
                p0 = p1;
                p1 = p2;
            }
            keep += p1;
        }
    }

    cout << (N - keep);
    return 0;
}
