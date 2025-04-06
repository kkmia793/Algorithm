#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    cin >> N;
    vector<int> C(2*N+1);
    vector<long long> X(N+1);
    
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> X[i];
    }
    for(int i = 1; i <= N; i++){
        C[i+N] = C[i];
    }
    
    int tot = 2 * N;
    vector<vector<long long>> dp(tot+1, vector<long long>(tot+1, INF));
    
    for(int i = 1; i <= tot; i++){
        dp[i][i] = 1 + X[C[i]];
    }
    
    for (int len = 2; len <= N; len++){
        for (int i = 1; i + len - 1 <= tot; i++){
            int j = i + len - 1;
            dp[i][j] = dp[i][j-1] + (1 + X[C[j]]);
            for (int k = i; k < j; k++){
                if(C[k] == C[j]){
                    long long mid = (k+1 <= j-1 ? dp[k+1][j-1] : 0LL);
                    dp[i][j] = min(dp[i][j], dp[i][k] + mid + (j - k));
                }
            }
        }
    }
    
    long long ans = INF;
    for (int start = 1; start <= N; start++){
        ans = min(ans, dp[start][start+N-1]);
    }
    cout << ans << "\n";
    return 0;
}
