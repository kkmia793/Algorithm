#include <bits/stdc++.h>
using namespace std;


// DP
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, Z;
    cin >> X >> Y >> Z; 
    string S; 
    cin >> S;
    int n = S.size();

    // dp0[i]: i文字目まで打ち終わり CapsLock OFF のときの最小時間
    // dp1[i]: i文字目まで打ち終わり CapsLock ON  のときの最小時間
    vector<long long> dp0(n+1, LLONG_MAX), dp1(n+1, LLONG_MAX);

    // 初期状態: CapsLock OFF で画面は空文字列(コスト0)
    dp0[0] = 0;
    // CapsLock ON にするには最初に Z ミリ秒かけて押す必要がある
    dp1[0] = Z;

    for(int i = 0; i < n; i++){
        // 今回打ちたい文字が 'a' か 'A' か
        char c = S[i];

        // CapsLock OFF 時に c を打つコスト (OFF なら 'a'、Shift なら 'A')
        long long costOff = (c == 'a' ? X : Y);
        // CapsLock ON 時に c を打つコスト  (ON なら 'A'、Shift なら 'a')
        long long costOn  = (c == 'a' ? Y : X);

        // i+1文字目を打ち終わった状態で CapsLock OFF
        // 1) もともとOFFのまま costOff を足す
        // 2) もともとON → Z でOFFにして → costOff
        dp0[i+1] = min(dp0[i] + costOff,
                       dp1[i] + Z + costOff);

        // i+1文字目を打ち終わった状態で CapsLock ON
        // 1) もともとONのまま costOn を足す
        // 2) もともとOFF → Z でONにして → costOn
        dp1[i+1] = min(dp1[i] + costOn,
                       dp0[i] + Z + costOn);
    }

    cout << min(dp0[n], dp1[n]) << "\n";
    return 0;
}
