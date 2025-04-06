#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[i][less]: i番目のビットを決める段階で、N未満が確定(less=1)かどうか
//              の状態から作れる最大値 (2進数) を返す。作れなければ -1。
static ll dp[70][2];
static bool used[70][2];

string s, b;  // s: 入力の2進パターン, b: Nを2進数に変換し桁合わせしたもの
int nlen;     // s, b の長さ

// 再帰関数: i番目のビットを決める (左から数えて i=0)
ll d(int i, int less) {
    // 末尾まで決めたら0 (これ以上ビットを加えない)
    if (i == nlen) return 0;
    // メモ化
    if (used[i][less]) return dp[i][less];
    used[i][less] = true;

    ll best = -1;  
    // Nのi番目のビット (0 or 1)
    int nb = b[i] - '0';

    // 選べるビット候補 (0 or 1)
    // s[i] == '0' なら 0 固定
    // s[i] == '1' なら 1 固定
    // s[i] == '?' なら 0 or 1 両方可
    vector<int> cands;
    if (s[i] == '0') cands = {0};
    else if (s[i] == '1') cands = {1};
    else cands = {0, 1}; // '?'

    for (int c : cands) {
        // まだ N と等しい範囲(less=0)の場合、 c <= nb でなければいけない
        if (!less && c > nb) continue;

        // 次の less 状態を決める
        int nl = less || (c < nb);

        // 再帰的に次のビット以降を決定
        ll nxt = d(i + 1, nl);
        if (nxt < 0) continue; // 不可能ならスキップ

        // このビットを c にしたときの実際の値
        // 左詰めなので (nlen - i - 1) ビット右に入る
        ll val = ((ll)c << (nlen - i - 1)) | nxt;
        best = max(best, val);
    }

    dp[i][less] = best;
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> s >> N;
    // s の長さ
    nlen = s.size();

    // N を2進数文字列 b に変換
    {
        // 一旦、2進数で生成
        string tmp;
        ll x = N;
        while (x > 0) {
            tmp.push_back(char('0' + (x & 1)));
            x >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        if (tmp.empty()) tmp = "0";

        // s と同じ長さになるよう先頭を '0' で埋める
        if ((int)tmp.size() < nlen) {
            string pad(nlen - tmp.size(), '0');
            b = pad + tmp;
        } else {
            // N の2進数が s より長い場合、先頭の余分を含める
            // ただし、N が s の長さより長い桁を持つ場合、s で作れる最大値より大きい可能性あり
            // そのまま使う (先頭のほうが長い分は s の制約が '0' なら無理な場合もある)
            // => DPで -1 になるかどうか判定
            if ((int)tmp.size() > nlen) {
                // b を tmp のまま使い、s を左ゼロ埋めする
                // ただし s を拡張してもOKかどうか → s の左に 0 で埋める
                int diff = tmp.size() - nlen;
                string pad(diff, '0');
                s = pad + s;
                nlen = tmp.size();
            }
            b = tmp;
        }
    }

    // メモを初期化
    memset(used, false, sizeof(used));

    ll ans = d(0, 0);
    cout << ans << "\n";

    return 0;
}
